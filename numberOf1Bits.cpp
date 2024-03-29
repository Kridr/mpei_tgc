//https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int zrs = 0;
        while (n) {
            zrs++;
            n &= n-1;
        }
        return zrs;
    }
};
