//https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    //dijkstra
    //we need to find the longest of the shortest ways to each nodes
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector <int> distance(N + 1, INT_MAX);


        //queue of nodes
        queue<int> q;
        q.push(K);

        //we need nothing to go from K to K
        distance[K] = 0;

        while (!q.empty()) {
            //taking the first elem of the queue and the deleting it
            int u = q.front();
            q.pop();

            //vector of target nodes from node "u"
            vector <pair<int,int>> nexts;

            //pushing back target nodes
            for (int i = 0; i < times.size(); i++) {
                if (times[i][0] == u) {
                    nexts.push_back(make_pair(times[i][1], times[i][2]));
                }
            }

            //crossing all pairs of the vector nexts
            for (auto next : nexts) {
                //we dont need to check node further if we find a shorter way to go for it
                if (distance[u] + next.second < distance[next.first]) {
                    distance[next.first] = distance[u] + next.second;
                    q.push(next.first);
                }
            }
        }

        int maxDistance = -1;

        //from 1 cause N > 0
        for (int i = 1; i < N + 1; i++) {
            maxDistance = max(maxDistance, distance[i]);
        }

        //if mD = intmax the we cannot go to some node
        return (maxDistance == INT_MAX) ? -1 : maxDistance;
    }
};
