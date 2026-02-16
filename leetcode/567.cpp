#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // basically i need to have a set of missing chars.
        unordered_map<char, int> required;
        unordered_map<char, int> have;
        int needed = s1.size();

        for (auto i = 0; i < s1.size(); ++i) {
            required[s1[i]]++;
        }

        for (auto i = 0; i < s2.size(); ++i) {
            // remove the previous elem
            if (i >= s1.size()) {
                char prev = s2[i - s1.size()];
                // check if this was needed or not
                if (have[prev] <= required[prev]) {
                    ++needed;
                }
                --have[prev];
            }

            // add the next char and see if it decreases needed.
            char ne = s2[i];
            if (have[ne] < required[ne]) {
                --needed;
            }
            ++have[ne];
            if (!needed) return true;
        }
        return false;
    }
};