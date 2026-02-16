#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto i : nums) {
            if (m.count(i)) {
                ++m[i];
            } else {
                m.insert({i, 0});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

        for (auto i : m) {
            pq.emplace(i.second, i.first);
        }

        vector<int> ret;
        for (auto i = 0; i < k; ++i) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};