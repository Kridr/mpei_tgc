//https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;

        Node* clone = new Node(node -> val, vector<Node*>());
        clones[node] = clone;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (auto neighbor: current -> neighbors) {
                if (clones.find(neighbor) == clones.end()) {
                    clones[neighbor] = new Node(neighbor -> val, vector<Node*>());
                    q.push(neighbor);
                }
                clones[current] -> neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }

private:
    unordered_map<Node*, Node*> clones;
};
