#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // greedy, take the one that gives you the most fuel which you can currently reach.
        priority_queue<int, vector<int>> mh;
        int total = startFuel;
        int ret = 0;
        for (int i = 0; i < stations.size(); ++i) {
            if (total >= target) return ret;
            if (stations[i][0] <= total) {
                mh.push(stations[i][1]);
            } else {
                // get the biggest elem and add to total;
                if (mh.empty()) return -1;
                total += mh.top();
                ++ret;
                mh.pop();
                --i;
            }
        }

        while (total < target) {
            if (mh.empty()) return -1;
            total += mh.top();
            ++ret;
            mh.pop();
        }

        if (total >= target) return ret;
        return -1;
    }
};