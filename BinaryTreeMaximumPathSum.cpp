//https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int trueMPS(TreeNode* root, int &maxSum) {
        if (root == NULL)
            return 0;
        int l = trueMPS(root -> left, maxSum);
        int r = trueMPS(root -> right, maxSum);

        if (l < 0)
            l = 0;

        if (r < 0)
            r = 0;

        if (l + r + root -> val > maxSum)
            maxSum = l + r + root -> val;

        return root -> val += max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        trueMPS(root, maxSum);

        return maxSum;
    }
};
