#include <bits/stdc++.h>
using namespace std;

// My own approach by counting the number of elements in left and right half
int singleNonDuplicate(vector<int> &nums)
{

    int n = nums.size();
    int l = 0;
    int h = n - 1;
    if (n == 1) return nums[0];

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (mid == 0 && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        else if (mid == n - 1 && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }

        else
        {
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];

            else if (nums[mid] == nums[mid - 1])
            {
                if ((mid + 1) & 1) h = mid - 1;
                else l = mid + 1;
            }

            else if (nums[mid] == nums[mid + 1])
            {
                if (mid & 1) h = mid - 1;
                else l = mid + 1;
            }
        }
    }

    return -1;
}

//Method -> 2
int singleNonDuplicate(vector<int>& nums) {
    
    int n = nums.size();
    int l = 0;
    int h = n-2;
    if(n == 1) return nums[0];
    
    while(l <= h)
    {
        int mid = (l + h) >> 1;
        
        if(nums[mid] == nums[mid ^ 1]) l = mid+1; // left half thik hai
        
        else h = mid - 1;
    }
    
    return nums[l];

    //left half
    //1st instance -> even index
    //2nd instance -> odd index
    // odd ^ 1 -> prev index(even)
    // even ^ 1 -> next index(odd)
}
int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums);
    return 0;
}