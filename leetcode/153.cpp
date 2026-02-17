#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findMin(vector<int>& nums) {
        // the problem is that i don't know how many rotations there have been.
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int prev = mid - 1;
            if (prev < 0) prev = nums.size() - 1;
            // check if min
            if (nums[mid] < nums[prev])  return nums[mid];
            
            if (nums[mid] < nums[high]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }
        return nums[high];
    }
};