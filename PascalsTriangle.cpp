//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        if (numRows == 0)
            return res;

        vector<int> first(1, 1);
        res.push_back(first);
        first.erase(first.begin(), first.end());
        for (int i = 2; i <= numRows; i++) {
            vector<int> resPart(i);

            resPart[0] = 1;
            resPart[i - 1] = 1;

            vector<int> prev = res[i - 2];

            for(int k = 1; k <= i - 2; k++)
                resPart[k] = prev[k - 1] + prev[k];

            res.push_back(resPart);

            resPart.erase(resPart.begin(), resPart.end());
        }

        return res;
    }
};
