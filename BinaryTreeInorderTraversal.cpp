//https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    void intro (vector <int> &x, TreeNode* rootx) {
        if (!rootx) {
            return;
        }
        intro (x, rootx -> left);

        x.push_back(rootx -> val);

        intro (x, rootx -> right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res;

        intro(res, root);

        return res;
    }
};
