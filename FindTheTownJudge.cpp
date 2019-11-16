//https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> res(N + 1, 0);
        vector<bool> is(N + 1, false);
        is[0] = true;

        for (int i = 0; i < trust.size(); i++) {
            res[trust[i][1]]++;
            is[trust[i][0]] = true;
        }

        for (int i = 0; i < N + 1; i++) {
            if (res[i] == N - 1 && !is[i]) {
                return i;
            }
        }

        return -1;
    }
};
