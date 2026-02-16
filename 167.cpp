#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // i can have two pointers such that 

        int big = numbers.size() - 1;
        int small = 0;

        while (numbers[big] + numbers[small] != target) {
            if (numbers[big] + numbers[small] > target) {
                --big;
            } else {
                ++small;
            }
        }

        return vector<int>{small + 1, big + 1};
    }
};