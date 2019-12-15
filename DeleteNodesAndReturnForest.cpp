//https://leetcode.com/problems/delete-nodes-and-return-forest/
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
    vector<TreeNode*> res;
    unordered_set<int> t_d_set;


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //create set to use find() func
        for (auto d : to_delete) {
            t_d_set.insert(d);
        }

        helper(root, res, t_d_set, true);
        return res;
    }

    TreeNode* helper(TreeNode* node, vector<TreeNode*>& res, unordered_set<int> t_d_set, bool isRoot) {
        if (node == NULL) {
            return NULL;
        }

        bool del = t_d_set.find(node -> val) != t_d_set.end();

        if (isRoot && !del) {
            res.push_back(node);
        }

        node -> left = helper(node -> left, res, t_d_set, del);
        node -> right = helper(node -> right, res, t_d_set, del);

        return del ? NULL : node;
    }

};
