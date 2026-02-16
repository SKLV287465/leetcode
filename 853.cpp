#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> ps;
        for (int i = 0; i < n; ++i) {
            ps.push_back({position[i], speed[i]});
        }
        sort(ps.rbegin(), ps.rend());

        vector<double> times;

        for (auto i = 0; i < n; ++i) {
            double t = (double) (target - ps[i].first) / (double) ps[i].second;
            if (times.empty()) {
                times.push_back(t);
            } else {
                // if it is slower than last time then add to back
                if (t > times.back()) {
                    times.push_back(t);
                }
            }
        }
        return times.size();
    }
};