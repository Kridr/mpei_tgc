//https://leetcode.com/problems/binary-tree-right-side-view/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<int> &res, int &height, int currentHeight = 0) {
        if (!root) {
            return;
        }
        if (currentHeight >= height) {
            res.push_back(root -> val);
            height++;
        }
        helper(root -> right, res, height, ++currentHeight);
        helper(root -> left, res, height, currentHeight);

    }

    vector<int> rightSideView(TreeNode* root) {
        int h, ch;
        vector <int> res;
        helper(root, res, h = 0, ch);
        return res;
    }
};
