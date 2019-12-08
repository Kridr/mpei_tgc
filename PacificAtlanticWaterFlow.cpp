//https://leetcode.com/problems/pacific-atlantic-water-flow/
class Solution {
public:
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int numRows = matrix.size();
        int numCols = matrix[0].size();

        vector<vector<int> > resVec;
        vector<vector<bool>> reachP(numRows, vector<bool>(numCols, false));
        vector<vector<bool>> reachA(numRows, vector<bool>(numCols, false));

        for (int i = 0; i < numRows; i++) {
            canReach(matrix, INT_MIN, i, 0, reachP);
            canReach(matrix, INT_MIN, i, numCols-1, reachA);
        }

        for (int i = 0; i < numCols; i++) {
            canReach(matrix, INT_MIN, 0, i, reachP);
            canReach(matrix, INT_MIN, numRows-1, i, reachA);
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (reachP[i][j] && reachA[i][j])
                    resVec.push_back({i, j});
            }
        }

        return resVec;
    }

private:
    void canReach(vector<vector<int>>& matrix, int preLevel, int i, int j, vector<vector<bool>>& visitedO) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] < preLevel || visitedO[i][j])
            return;

        visitedO[i][j] = true;
        preLevel = matrix[i][j];

        canReach(matrix, preLevel, i+1, j, visitedO);
        canReach(matrix, preLevel, i-1, j, visitedO);
        canReach(matrix, preLevel, i, j+1, visitedO);
        canReach(matrix, preLevel, i, j-1, visitedO);
    }
};
