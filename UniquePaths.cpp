//https://leetcode.com/problems/unique-paths/
class Solution {
public:

    int uniquePaths(int m, int n) {
        //number of steps
        double N = m + n - 2;

        //number of steps down
        double K = min(n - 1, m - 1);

        //if we do a step down then we cannot further do a step up
        //and hence we reduce the count of possible ways

        //we have m-1 steps right and n-1 steps down
        double res = 1;
        //C(N, K):
        for (int i = 1; i <= K; i++) {
            res *= (N - K + i) / i;
        }

        return round(res);
    }
};
