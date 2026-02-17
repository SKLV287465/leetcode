#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        int ret = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++ret;
                    queue<pair<int, int>> q;
                    q.push({i , j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        auto x = q.front();
                        q.pop();
                        if (x.first > 0 && grid[x.first - 1][x.second] == '1') {
                            q.push({x.first - 1, x.second});
                            grid[x.first - 1][x.second] = '0';
                        } 
                        if (x.first < n - 1 && grid[x.first + 1][x.second] == '1') {
                            q.push({x.first + 1, x.second});
                            grid[x.first + 1][x.second] = '0';
                        }
                        if (x.second > 0 && grid[x.first][x.second - 1] == '1') {
                            q.push({x.first, x.second - 1});
                            grid[x.first][x.second - 1] = '0';
                        }
                        if (x.second < m - 1 && grid[x.first][x.second + 1] == '1') {
                            q.push({x.first, x.second + 1});
                            grid[x.first][x.second + 1] = '0';
                        }
                    }
                }
            }
        }
        return ret;
    }
};