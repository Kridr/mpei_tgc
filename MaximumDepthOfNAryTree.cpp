//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void helper(Node* root, int cd, int &md) {
        if (!root)
            return;
        for(auto n : root -> children)
            helper(n, cd + 1, (cd + 1 > md) ? (++md) : md);
    }

    int maxDepth(Node* root) {
        int cd = 1, md = (!root) ? 0 : 1;
        helper(root, cd, md);
        return md;
    }
};
