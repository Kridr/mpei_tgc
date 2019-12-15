//https://leetcode.com/problems/rectangle-area/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //x coords of crossings
        int left = max(A, E);
        int right = max(min(C, G), left);

        //y coords of crossing
        int low = max(B, F);
        int high = max(min(D, H), low);

        //inclusion–exclusion principle
        //we subtract firstly to prevent integer ovetflow
        return (C-A)*(D-B) - (right-left)*(high-low) + (G-E)*(H-F);
    }
};
