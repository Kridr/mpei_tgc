//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;


        //go through all elems
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    deleteIsland(grid, i, j);
                }
            }
        }

        return islands;
    }

    void deleteIsland(vector<vector<char>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();

        //escape cons
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }

        //deleting the part of island
        grid[i][j] = '0';

        //spread deleting
        deleteIsland(grid, i + 1, j);
        deleteIsland(grid, i, j + 1);
        deleteIsland(grid, i - 1, j);
        deleteIsland(grid, i, j - 1);

    }
};
