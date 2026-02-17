#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxcount = 0;
        int maxc = 1;
        int diffs = 0;
        char maxchar = s.front();
        int freqs[26];
        memset(freqs, 0, 104);
        freqs[maxchar - 'A'] = 1;
        for (int i = 1; i < s.size(); ++i) {
            char nc = s[i];
            ++freqs[nc - 'A'];
            if (freqs[nc - 'A'] > maxc) {
                maxc = freqs[nc - 'A'];
                maxchar = nc;
            } else if (nc == maxchar) {
                ++maxc;
            } else {
                maxcount = max(maxcount, diffs + maxc);
                ++diffs;
                if (diffs > k) {
                    // remove the last elem.
                    // count is maxchar + diffs;
                    int count = maxc + diffs;
                    char lc = s[i - count];
                    if (lc == maxchar) {
                        --maxc;
                    } else {
                        --diffs;
                    }
                    --freqs[lc - 'A'];
                    // maybe i need to do a scan, hopefully not.
                }
            }
        }
        return maxcount;
    }
};