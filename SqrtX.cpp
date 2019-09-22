//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        unsigned int res = exp(log(x)/2);
        return ((res + 1)*(res + 1)  == x) ? res + 1 : res;
    }
};
