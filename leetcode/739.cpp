#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<pair<int, int>> tmps;
        for (auto i = 0; i < temperatures.size(); ++i) {
            // look into the stack 
            if (tmps.empty()) {
                tmps.push({temperatures[i], 0});
            } else {
                // look into the stack to see if it is greater than any
                int counter = 1;
                int secondcounter = 0;
                while (!tmps.empty() && temperatures[i] > tmps.top().first) {
                    secondcounter += tmps.top().second;
                    ret[i - counter - secondcounter] = counter + secondcounter;
                    tmps.pop();
                    ++counter;
                }
                if (!tmps.empty()) {
                    tmps.top().second += secondcounter + counter - 1;
                }
                tmps.push({temperatures[i], 0});
            }
        }
        return ret;
    }
};