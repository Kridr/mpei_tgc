//https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.length(), 0);

        int level = 0;
        int i = 0;

        while (i < seq.size()) {

            //level up
            if (seq[i] == '(') {
                res[i] = ++level % 2;
            //level down
            } else {
                res[i] = level-- % 2;
            }

            i++;
        }

        return res;
    }
};
