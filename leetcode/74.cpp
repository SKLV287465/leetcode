#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;
    int getRow(int x) {
        return x / cols;
    }

    int getCol(int x) {
        return x % cols;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // row then col.
        rows = matrix.size();
        cols = matrix.front().size();
        int high = rows * cols - 1;

        // do binary search on total

        int low = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[getRow(mid)][getCol(mid)] == target) {
                return true;
            }

            if (matrix[getRow(mid)][getCol(mid)] < target) {
                low = mid + 1;
            }  else {
                high = mid - 1;
            }
        }
        return false;
    }
};