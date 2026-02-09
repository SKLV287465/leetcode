#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        ret[0] = nums[0];
        for (auto i = 1; i < nums.size() - 1; ++i) {
            ret[i] = ret[i - 1] * nums[i];

        }
        ret[ret.size() - 1] = ret[ret.size() - 2];
        int prev = nums[ret.size() - 1];
        for (auto i = nums.size() - 2; i > 0; --i) {
            int placeholder = ret[i];
            ret[i] = prev * ret[i - 1];
            prev *= placeholder;
        }
        ret[0] = prev;

        return ret;
    }
};