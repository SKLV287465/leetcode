#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // basically move the shorter side until there is a bigger height
        int ma = min(height.front(), height.back()) * (height.size() - 1);
        int small = 0;
        int big = height.size() - 1;

        while (big != small) {
            if (height[big] > height[small]) {
                ++small;
            } else if (height[small] > height[big]) {
                --big;
            } else {
                if (small + 1 == big) return ma;
                ++small;
                --big;
            }
            int candidate = min(height[small], height[big]) * (big - small);
            ma = max(candidate, ma);
        }

        return ma;
    }
};