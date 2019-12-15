//https://leetcode.com/problems/add-one-row-to-tree/
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return helper(root, v, d, true);
    }


    //helper needs to realize where we must add root
    TreeNode* helper(TreeNode* root, int v, int d, bool isLeft) {
        if (root == NULL) {
            return (d == 1) ? new TreeNode(v) : NULL;
        }

        if (d == 1) {
            TreeNode* temp = new TreeNode(v);
            if (isLeft) {
                temp -> left = root;
            } else {
                temp -> right = root;
            }

            return temp;
        }

        root -> left = helper(root -> left, v, d - 1, true);
        root -> right = helper(root -> right, v, d - 1, false);

        return root;
    }
};
