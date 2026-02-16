#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long maxi = ideas.size() * (ideas.size() - 1);
        vector<int> starts(26, 0);
        unordered_map<string, pair<int, unordered_set<int>>> tails;
        for (int i = 0; i < ideas.size(); ++i) {
            ++starts[ideas[i][0] - 'a'];
            string to_insert = ideas[i].substr(1, ideas[i].size() - 1);
            if (tails.count(to_insert)) {
                ++tails[to_insert].first;
                tails[to_insert].second.insert(ideas[i][0] - 'a');
            } else {
                tails.insert({move(to_insert), {0, unordered_set<int>{ideas[i][0] - 'a'}}});
            }
        }
        // remove all the identical starts
        for (int i = 0; i < 26; ++i) {
            maxi -= starts[i] * (starts[i] - 1);
        }

        // find all the identical tails.
        for (auto& elem : tails) {
            for (auto c : elem.second.second) {
                maxi -= starts[c];
            }
        }
        return maxi;
    }
};