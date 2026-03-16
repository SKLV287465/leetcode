#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_set<int> used;
        unordered_map<int, int> overlaps;
        int count = 0;
        for (auto i : nums) {
            if (used.count(i)) {
                ++overlaps[i];
            } else {
                ++count;
            }
        }
        for (auto [a, b] : overlaps) {
            for (auto i = 0; i < b; ++i) {
                if (used.count(a - k))
            }
        }
    }
};
