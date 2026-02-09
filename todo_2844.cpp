#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
       bool foundzero = false, foundfive = false;
       for (int i = num.size() - 1; i >= 0; --i) {
            int cur = num[i] - '0';
            if (cur == 0 || cur == 5) {
                if (foundzero) return num.size() - 2 - i;
            }
            if (cur == 2 || cur == 7) {
                if (foundfive) return num.size() - 2 - i;
            }
            if (num[i] == '5') foundfive = true;
            if (num[i] == '0') foundzero = true;
       }
       if (foundzero) return num.size() - 1;
       return num.size();
    }

};
// cases are
// 00
// 25
// 50
// 75