//https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
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
    TreeNode* recoverFromPreorder(string S) {
        //it is convenient to store elem as a stack
        //but it is more convenient to use vector as a stack
        //the speed is equal because stack is container adapter
        vector<TreeNode*> stack;
        for (int i = 0, level, val; i < S.length();) {
            //level equal depth
            for (level = 0; S[i] == '-'; i++)
                level++;

            //build val
            for (val = 0; i < S.length() && S[i] != '-'; i++)
                val = val * 10 + S[i] - '0';

            TreeNode* node = new TreeNode(val);

            //we do this to find the elem, which will be connected with our node
            while (stack.size() > level)
                stack.pop_back();

            //priority: left, right
            if (!stack.empty())
                if (!stack.back() -> left)
                    stack.back() -> left = node;
                else
                    stack.back() -> right = node;

            //dont forget to add our node to stack
            stack.push_back(node);
        }

        //stack[0] is root of our tree (u can check it)
        return stack[0];
    }
};
