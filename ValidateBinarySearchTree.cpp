//https://leetcode.com/problems/validate-binary-search-tree/
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
    bool helper(TreeNode* root, long long int min, long long int max) {
        if (root == NULL)
            return true;
        else if (root -> val > min && root -> val < max)
            return helper(root -> left, min, root -> val) && helper(root -> right, root -> val, max);
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int min = LLONG_MIN;
        long long int max = LLONG_MAX;

        return helper (root, min, max);
    }
};
