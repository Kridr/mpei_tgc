//https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int> > > gr(n);

        for (auto flight : flights) {
            gr[flight[0]].push_back({flight[1], flight[2]});
        }

        int minPrice = INT_MAX;

        //source, stops, price
        queue<vector<int> > q;
        q.push({src, 0, 0});

        while(!q.empty()) {
            vector<int> u = q.front();
            q.pop();

            if (u[0] == dst) {
                minPrice = min(minPrice, u[2]);
            }

            if (u[1] <= K && u[2] <= minPrice) {
                for (auto t : gr[u[0]]) {
                    q.push({t.first, u[1] + 1, u[2] + t.second});
                }
            }
        }

        return (minPrice == INT_MAX) ? -1 : minPrice;
    }
};
