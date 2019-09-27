//https://leetcode.com/problems/non-decreasing-array/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        if (n < 3) return true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                cnt++;
                if (cnt > 1)
                    return false;

                int prev = i > 0 ? nums[i - 1] : INT_MIN;
                int nxt = i + 2 < n ? nums[i + 2] : INT_MAX;

                if (prev > nums[i + 1] && nums[i] > nxt)
                    return false;
            }
        }
        return true;
    }
};
