//https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pq) {
        vector<vector<int> > gr(n, vector<int>());
        vector<int> ind(n, 0);

        for (auto v: pq) {
            gr[v[1]].push_back(v[0]);
            ind[v[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (ind[i] == 0)
                q.push(i);
        }

        vector<int> path;
        int size = 0;
        while(!q.empty()) {
            size++;

            int u = q.front();
            path.push_back(u);
            q.pop();

            for (auto e: gr[u]) {
                ind[e]--;
                if (ind[e] == 0)
                    q.push(e);
            }
        }

        return (size == n) ? path : vector<int>();
    }
};
