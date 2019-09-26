//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {

        //the solution is to randomly pick two number and believe
        //by the way, the chance is 25%
        int i = 0, j = 0, sz = A.size();
        while (i == j || A[i] != A[j]) {
            i = rand() % sz;
            j = rand() % sz;
        }
        return A[i];

    }
};
