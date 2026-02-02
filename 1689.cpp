#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        // its probably the biggest int inside the thing
        char largest = '0';
        for (int i = 0; i < n.size(); ++i) {
            largest = max(largest, n[i]);
        }
        return largest - 48;
    }
};