#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int n) { 
        if (n == 1) return 1;
        // do all multiplications first
        // then do all divisions
        // then do all additions
        // then do all subtractions
        vector<long long> values1;
        vector<long long> values2;
        vector<long long> values3;
        vector<long long> values4;
        // fill the value array first
        for (long long i = n; i > 0; --i) {
            values1.push_back(i);
        }
        // do the multiplication and division
        for (long long i = 0; i < n; ++i) {
            if (i % 4 == 0) {
                long long nv = values1[i];
                int inc = 0;
                if (i < values1.size() - 1) {
                    nv *= values1[i + 1];
                    ++inc;
                }
                if (i < values1.size() - 2) {
                    nv /= values1[i + 2];
                    ++inc;
                }
                values2.push_back(nv);
                i += inc;
            } else {
                values2.push_back(values1[i]);
            }
        }
        long long value = 0;
        for (int i = 0; i < values2.size(); ++i) {
            if (i == 0) {
                value += values2[i];
            } else if (i % 2 == 1){
                value += values2[i];
            } else {
                value -= values2[i];
            }
        }
        return value;
        
    }
};

// * / + -