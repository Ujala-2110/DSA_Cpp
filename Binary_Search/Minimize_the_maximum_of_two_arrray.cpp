// We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:

// arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
// arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
// No integer is present in both arr1 and arr2.
// Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.

// Example 1:

// Input: divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
// Output: 4
// Explanation: 
// We can distribute the first 4 natural numbers into arr1 and arr2.
// arr1 = [1] and arr2 = [2,3,4].
// We can see that both arrays satisfy all the conditions.
// Since the maximum value is 4, we return it.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {

private:
    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a % b);
    }
    int lcm(ll a, ll b) {
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }

public:
    int minimizeSet(int d1, int d2, int needA, int needB) {
        
        int l = 0, r = INT_MAX;
        int LCM = lcm(d1,d2);

        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            int a = mid/d1 , b = mid/d2;
            if(needA <= mid -a && needB <= mid - b && (needA+needB) <= mid - (mid/LCM)) r = mid-1;
            else l = mid+1;
        }

        return l;
    }
};

// Intuition
// When you have to minimise/maximise, there's a very high chance you can binary search on the answer. Here if we know a number X provides us enough numbers to fulfill both conditions, then we can simply look for a number smaller than X which might satisfy the condition, if not we will look for a larger number. Now the question is to just check if a number X satisfies the condition or not.

// Approach
// Now to check if a number X satisfies the condition or not, we will first calculate how many numbers are there from 1...X that are divisible by divisor1 and divisor2. We can find out this by dividing X by divisor1, i.e. divisibleByD1 = X / divisor1. Then we can do the same for divisor2, i.e. divisibleByD2 = X / divisor2. Now the number of integers that we can add to the first array are elements1 = X - divisibleByD1 and number of elements we can add to the second array are elements2 = X - divisibleByD2. If you notice here there might be an overlap. For e.g. divisor1 = 4 and divisor2 = 6 and X = 13. Here divisibleByD1 = 3 { 4, 8, 12 } and divisibleByD2 = 2 { 6, 12 }. These are the elements that we cannot use in either array1 or array2. But there's an overlap of 12 which we can't use in either of the arrays but we've calulated it twice. To solve this, we will also calulate the number of elements divible by both divisor1 and divisor2 (which is number of elements divisble by lcm(divisor1, divisor2)) (this finds out the overlapping elements). Now X will satisfy the condition if uniqueCnt1 <= elements1 && uniqueCnt2 <= elements2 && uniqueCnt1 + uniqueCnt2 <= X - (X / LCM).

// Complexity
// Time complexity: log2(INT_MAX)​ + log2(a+b) (to find gcd of two numbers) essentially log2(N)
// Space complexity: O(1)


// Method->2
// 1. One array
// Think of there is just one array to fill, and only one divisor d, array length need.

// Count from 1 to n, every d numbers we could take d-1 to fill the array, just drop multiples of d and take all the rest. So if we need need numbers, the max number counted is need / (d-1) * d.

// But how about if need is multiple of d-1? then need / (d-1) * d is exactly also a multiple of d, its useless, we should minus it by 1, it will be need / (d-1) * d - 1.

// Let's call this solution as solve(d, need), equals to need * d / (d-1) - (need % (d-1) ? 0 : 1).

// 2. Two arrays
// Then think of two arrays, one with divisor d1 and length need1, another d2 and need2.

// Count from 1 to n, we only drop common multiples of d1 and d2, then divide the rest numbers into 3 types.

// numbers could only fill array1, that means multiples of d2, mark total count of these numbers as m1.
// numbers could only fill array2, that means multiples of d1, mark total count of these numbers as m2.
// numbers could fill both array1 and array2, that means nether multiples of d1 nor multiples of d2, mark total count of these type of numbers as m0.
// We count need1 + nees2 numbers, so now m1 + m2 + m0 == need1 + nees2.

// if m1 <= need1 <= m1 + m0, then we must get m2 <= need2 <= m2 + m0,
// in this case, numbers we counted are enough to fill the two arrays,
// so the result is solve(lcm(d1, d2), need1+need2).

// if need1 < m1, then we must get need2 > m2 + m0, then we should count more numbers to fill array2, only drop multiples of d2, the result is solve(d2, need2).

// if need2 < m2, same to above, the result is solve(d1, need1).

// The final result is the max result of these 3 conditions.

// Code
// class Solution {
//     long gcd(long a, long b) {
//         return b == 0 ? a : gcd(b, a % b);
//     }
//     long lcm(long a, long b) {
//         return a / gcd(a, b) * b;
//     }

//     // Solution about just one divisor
//     int solve(unsigned long d, unsigned long need) {
//         return need * d / (d-1) - (need % (d-1) ? 0 : 1);
//     }

// public:
//     int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
//         long l = lcm(divisor1, divisor2);
//         int s = uniqueCnt1 + uniqueCnt2;
//         // Final result is the max result of these three conditions
//         return max({solve(l, s), solve(divisor1, uniqueCnt1), solve(divisor2, uniqueCnt2)});
//     }
// };
// Method->2
// 1. One array
// Think of there is just one array to fill, and only one divisor d, array length need.

// Count from 1 to n, every d numbers we could take d-1 to fill the array, just drop multiples of d and take all the rest. So if we need need numbers, the max number counted is need / (d-1) * d.

// But how about if need is multiple of d-1? then need / (d-1) * d is exactly also a multiple of d, its useless, we should minus it by 1, it will be need / (d-1) * d - 1.

// Let's call this solution as solve(d, need), equals to need * d / (d-1) - (need % (d-1) ? 0 : 1).

// 2. Two arrays
// Then think of two arrays, one with divisor d1 and length need1, another d2 and need2.

// Count from 1 to n, we only drop common multiples of d1 and d2, then divide the rest numbers into 3 types.

// numbers could only fill array1, that means multiples of d2, mark total count of these numbers as m1.
// numbers could only fill array2, that means multiples of d1, mark total count of these numbers as m2.
// numbers could fill both array1 and array2, that means nether multiples of d1 nor multiples of d2, mark total count of these type of numbers as m0.
// We count need1 + nees2 numbers, so now m1 + m2 + m0 == need1 + nees2.

// if m1 <= need1 <= m1 + m0, then we must get m2 <= need2 <= m2 + m0,
// in this case, numbers we counted are enough to fill the two arrays,
// so the result is solve(lcm(d1, d2), need1+need2).

// if need1 < m1, then we must get need2 > m2 + m0, then we should count more numbers to fill array2, only drop multiples of d2, the result is solve(d2, need2).

// if need2 < m2, same to above, the result is solve(d1, need1).

// The final result is the max result of these 3 conditions.

// Code
class Solution {
    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    int solve(unsigned long d, unsigned long need) {
        return need * d / (d-1) - (need % (d-1) ? 0 : 1);
    }

public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long l = lcm(divisor1, divisor2);
        int s = uniqueCnt1 + uniqueCnt2;
        // Final result is the max result of these three conditions
        return max({solve(l, s), solve(divisor1, uniqueCnt1), solve(divisor2, uniqueCnt2)});
    }
};