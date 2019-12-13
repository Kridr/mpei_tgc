//https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty()) {
            return {};
        }

        //value - frequency
        unordered_map<int,int> map;
        for (auto num : nums) {
            map[num]++;
        }

        //barely heap (randomly filled massive at the moment)
        vector<pair<int,int> > heap;
        for (auto m : map) {
            heap.push_back({m.second, m.first});
        }

        //stl function, cause i dont want to make my own one
        make_heap(heap.begin(), heap.end());

        vector<int> res;

        //heap -> res;
        while (k--) {
            //adding top of heap (value) to result
            res.push_back(heap.front().second);
            //move top to end
            pop_heap(heap.begin(), heap.end());
            //delete that shit(look up)
            heap.pop_back();
        }

        return res;
    }
};
