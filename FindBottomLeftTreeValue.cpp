//https://leetcode.com/problems/find-bottom-left-tree-value/
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        //insane, isn't it?
        //when we do right-to-left bfs,
        //we will get the leftmost value
        while(!q.empty()) {
            root = q.front();
            q.pop();

            if (root -> right != NULL)
                q.push(root -> right);
            if (root -> left != NULL)
                q.push(root -> left);
        }

        return root -> val;
    }
};
