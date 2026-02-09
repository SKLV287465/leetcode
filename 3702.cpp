#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int thing = 0;
        int zeros = 0;
        for (int i = 0; i < nums.size(); ++i) {
            thing ^= nums[i];
            if (nums[i] == 0) ++zeros;
        }
        if (thing) return nums.size();
        if (zeros == nums.size()) return 0;
        return nums.size() - 1;
    }
};