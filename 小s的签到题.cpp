#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using bs = bitset<10>; // 最多只有10个'L'

    vector<int> get_start(vector<string>& grid) {
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid[0].size(); ++y) {
                if (grid[x][y] == 'S') {
                    return {x, y};
                }
            }
        }
        return {-1, -1}; // 不会到这里
    }

    vector<vector<int>> make_mark(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> idx(n, vector<int>(m, -1));
        int cur = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (grid[x][y] == 'L') {
                    idx[x][y] = cur++;
                }
            }
        }
        return idx;
    }

    int count(vector<string>& grid) {
        int res = 0;
        for (auto& row : grid)
            for (char ch : row)
                if (ch == 'L') ++res;
        return res;
    }

    int minMoves(vector<string>& grid, int energy) {
        int n = grid.size(), m = grid[0].size();
        int cnt = count(grid);
        auto idxs = make_mark(grid);
        vector<int> start = get_start(grid);
        grid[start[0]][start[1]] = '.';

        const int inf = 0x3f3f3f3f;
        vector<vector<unordered_map<int, vector<int>>>> dp(n, vector<unordered_map<int, vector<int>>>(m));

        queue<tuple<int, int, bs, int, int>> qu;
        bs empty;
        qu.push({start[0], start[1], empty, energy, 0});

        const vector<int> dx = {1, 0, -1, 0};
        const vector<int> dy = {0, 1, 0, -1};

        while (!qu.empty()) {
            auto [x, y, collected, e, steps] = qu.front();
            qu.pop();

            int bmask = static_cast<int>(collected.to_ulong());
            if (dp[x][y][bmask].empty()) {
                dp[x][y][bmask].resize(energy + 1, inf);
            }
            if (steps >= dp[x][y][bmask][e]) continue;
            dp[x][y][bmask][e] = steps;

            if (collected.count() == cnt) return steps;

            if (e == 0) continue;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                char ch = grid[nx][ny];
                if (ch == 'X') continue;

                bs next_collected = collected;
                int next_energy = e - 1;

                if (ch == 'L') {
                    int id = idxs[nx][ny];
                    next_collected.set(id);
                } else if (ch == 'R') {
                    next_energy = energy;
                }

                int next_mask = static_cast<int>(next_collected.to_ulong());

                if (dp[nx][ny][next_mask].empty()) {
                    dp[nx][ny][next_mask].resize(energy + 1, inf);
                }
                if (steps + 1 < dp[nx][ny][next_mask][next_energy]) {
                    qu.push({nx, ny, next_collected, next_energy, steps + 1});
                }
            }
        }

        return -1;
    }
};
