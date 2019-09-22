//https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    void rec(long int deg, int n, int &zrs) {
        if (n >= deg) {
            zrs += (n / deg);
            rec(5*deg, n, zrs);
        }
    }

    int trailingZeroes(int n) {
        int zrs = 0;
        long int deg = 5;
        rec(deg, n, zrs);
        return zrs;
    }
};
