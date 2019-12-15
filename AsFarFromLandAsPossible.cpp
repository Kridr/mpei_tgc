//https://leetcode.com/problems/as-far-from-land-as-possible/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int> > q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        if (q.empty() || q.size() == grid[0].size()*grid.size()) {
            return -1;
        }

        int maxDist = 0;

        while(!q.empty()) {
            auto u = q.front();
            q.pop();

            if (u.first + 1 < grid.size() && grid[u.first + 1][u.second] == 0) {
                q.push({u.first + 1, u.second});

                grid[u.first + 1][u.second] = grid[u.first][u.second] + 1;

                maxDist = max(maxDist, grid[u.first + 1][u.second]);
            }

            if (u.first - 1 >= 0  && grid[u.first - 1][u.second] == 0) {
                q.push({u.first - 1, u.second});

                grid[u.first - 1][u.second] = grid[u.first][u.second] + 1;

                maxDist = max(maxDist, grid[u.first - 1][u.second]);
            }

            if (u.second + 1 < grid[0].size() && grid[u.first][u.second + 1] == 0) {
                q.push({u.first, u.second + 1});

                grid[u.first][u.second + 1] = grid[u.first][u.second] + 1;

                maxDist = max(maxDist, grid[u.first][u.second + 1]);
            }

            if (u.second - 1 >= 0 && grid[u.first][u.second - 1] == 0) {
                q.push({u.first, u.second - 1});

                grid[u.first][u.second - 1] = grid[u.first][u.second] + 1;

                maxDist = max(maxDist, grid[u.first][u.second - 1]);
            }
        }

        return maxDist - 1;
    }
};
