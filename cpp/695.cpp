#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ma = 0;
        int n = grid.size();
        int m = grid.front().size();
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    cur = 1;
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        auto coords = q.front();
                        q.pop();
                        if (coords.first > 0 && grid[coords.first - 1][coords.second]) {
                            ++cur;
                            grid[coords.first - 1][coords.second] = 0;
                            q.push({coords.first - 1, coords.second});
                        } 
                        if (coords.first < n - 1 && grid[coords.first + 1][coords.second]) {
                            ++cur;
                            grid[coords.first + 1][coords.second] = 0;
                            q.push({coords.first + 1, coords.second});
                        } 
                        if (coords.second > 0 && grid[coords.first][coords.second - 1]) {
                            ++cur;
                            grid[coords.first][coords.second - 1] = 0;
                            q.push({coords.first, coords.second - 1});
                        } 
                        if (coords.second < m - 1 && grid[coords.first][coords.second + 1]) {
                            ++cur;
                            grid[coords.first][coords.second + 1] = 0;
                            q.push({coords.first, coords.second + 1});
                        } 
                    }
                    ma = max(ma, cur);
                }
            }
        }
        return ma;
    }
};