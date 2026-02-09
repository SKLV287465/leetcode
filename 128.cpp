#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int longest = 0;
        int prev = nums[0];
        int cur = 1;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] - prev == 1) {
                ++cur;
                prev = nums[i];
            } else if (nums[i] == prev) {
                continue;
            }
            
            else {
                longest = max(cur, longest);
                prev = nums[i];
                cur = 1;
            }
        }
        longest = max(longest, cur);
        return longest;
    }
};