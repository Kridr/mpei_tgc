//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    //To make sure min/max values belong to an ancestor, we track min/max from the root till the leaf,
    //and pick the biggest difference among all leaves.
    int maxAncestorDiff(TreeNode* root, int mn = INT_MAX, int mx = INT_MIN) {
        if (root == nullptr) return mx - mn;
        mx = max(mx, root -> val);
        mn = min(mn, root -> val);
        return max(maxAncestorDiff(root -> left, mn, mx), maxAncestorDiff(root -> right, mn, mx));
    }
};
