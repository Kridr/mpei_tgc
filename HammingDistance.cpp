//https://leetcode.com/problems/hamming-distance/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int dist = 0;

        while(res) {
            dist++;
            res &= res - 1;
        }
        return dist;
    }
};
