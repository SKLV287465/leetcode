#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string ret;
        for (auto s : strs) {
            ret.append(s);
            ret += 256;
        }
        return ret;
    }

    vector<string> decode(string s) {
        stringstream ss(s);

        vector<string> ret;
        string token;
        while (getline(ss, token, char (256))) {
            ret.push_back(token);
        }
        return ret;
    }
};

