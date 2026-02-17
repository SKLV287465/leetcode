#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    inline long hours_taken(long long k, vector<int>& piles) {
        long long ret = 0;
        for (auto i : piles) {
            ret += i / k;
            if (i % k) ++ret;
        }
        return ret;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // basically do binary search on k, 
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long mid, ht;
        while (low <= high) {
            mid = low + (high - low) / 2;
            ht = hours_taken(mid, piles);

            if (ht > h) {
                // reduce mid
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};