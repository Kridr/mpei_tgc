//https://leetcode.com/problems/redundant-connection/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(edges.size() + 1, 0);
        for(int i = 0; i < p.size(); i++ )
            p[i] = i;

        vector<int> res;
        for(auto v : edges) {
            int n1 = v[0], n2 = v[1];
            //searching for ancestors
            while(n1 != p[n1]) n1 = p[n1];
            while(n2 != p[n2]) n2 = p[n2];
            //if n1 and n2 have the same ancestor, we have triple link, else we create ancestor's link
            if (n1 == n2)
                res = v;
            else
                p[n1] = n2;
        }
        return res;
    }
};
