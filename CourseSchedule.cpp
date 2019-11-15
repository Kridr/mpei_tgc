//https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& depends) {
        //vec to create topological sort
        vector<int> res;

        //vector represents how many times the node is the condition
        vector<int> c(n, 0);

        //perform graph to an appropriate form(as a matrix)
        //j is node ; a[j] is needed nodes;
        vector<vector<int>> graph(n, vector<int>());

        //performing itself
        for (auto &d : depends) {
            auto node = d[0];
            auto condition = d[1];
            c[condition]++;
            graph[node].push_back(condition);
        }

        //find all start nodes(nodes which are not con to others)
        queue<int> start;
        for (int node = 0; node < n; node++) {
            if (c[node] == 0) {
                start.push(node);
            }
        }

        //the algo itself
        while (!start.empty()) {
            auto node = start.front();
            start.pop();
            res.push_back(node);
            for (auto peer : graph[node]) {
                c[peer]--;
                if (c[peer] == 0) {
                    start.push(peer);
                }
            }
        }

        //if the sort has gone successfully we must get true(it means we dont have cycles)
        return res.size() == n;
    }
};
