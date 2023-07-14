#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{

    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;

        //left half is sorted
        if (nums[low] <= nums[mid])
        {
            //element is present in this range but not at mid
            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        //right half is sorted
        else
        {
            //element is present in this range but not at mid
            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 6;
    cout <<"Element present at position "<< search(nums, target);
    return 0;
}