//https://leetcode.com/problems/shortest-path-with-alternating-colors/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        //graph representation
        //index: neighbor indexes & their colors
        vector<vector<pair<int,int> > > gr(n);

        //filling graph with blue and red nodes
        //red: 0; blue: 1
        for (auto& v: red_edges)
            gr[v[0]].push_back({v[1], 0});
        for (auto& v: blue_edges)
            gr[v[0]].push_back({v[1], 1});

        //helping structure to build final result and to check repeats(usage)
        vector<vector<int> > vCost(n, vector<int>(2, -1));
        //starting node
        vCost[0] = {0, 0};

        //index, color
        queue<pair<int,int>> q;

        //starting with node 0, consider it as a red one and a blue one
        q.push({0, 0});
        q.push({0, 1});

        //bfs
        while(!q.empty()) {
            //standart actions
            auto [i, c1] = q.front();
            q.pop();

            //checking all neighbors
            for(auto [j, c2] : gr[i]) {
                //if we already found the shortest path,
                //or we interrupted the condition of alternating
                //then skip the neighbor
                if (vCost[j][c2] != -1 || c1 == c2)
                    continue;

                //increase the length of the shortest path
                vCost[j][c2] = 1 + vCost[i][c1];

                //adding to queue
                q.push({j, c2});
            }
        }

        //final result
        vector<int> res;

        //filling result vector
        for (auto& v : vCost) {
            //need to build the right answer
            sort(v.begin(), v.end());
            res.push_back(v[0] != -1 ? v[0] : v[1]);
        }

        return res;
    }
};
