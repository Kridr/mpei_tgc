//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //terminal conditions
        if (nums.size() == 0)
            return NULL;
        if (nums.size() == 1)
            return new TreeNode(nums[0]);

        //start from middle to make depths of all branches equal
        int middle = nums.size()/2;
        TreeNode* root = new TreeNode(nums[middle]);

        //so that we compute right and left sides separatly
        vector<int> leftSide (nums.begin(), nums.begin() + middle);
        vector<int> rightSide (nums.begin() + middle + 1, nums.end());

        //build a tree
        root -> left = sortedArrayToBST(leftSide);
        root -> right = sortedArrayToBST(rightSide);

        return root;
    }
};
