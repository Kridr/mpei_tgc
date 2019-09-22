//https://leetcode.com/problems/permutation-sequence/
class Solution {
public:

    string getPermutation(int n, int k) {
        k--;

       vector <char> perm(n);

       vector <int> nums;
       for (int i = 0; i < n; i++) {
         nums.push_back(i + 1);
       }

       int fact[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; //till 8
       for (int i = 1; i < n - 1; i++) {
         int temp = 0;
         temp = k / fact[n - i] + 1;
         k = k - (temp - 1)*(fact[n - i]);

         perm[i - 1] = nums[temp - 1] + '0';
         nums.erase(nums.begin() + temp - 1);
       }
       if (n > 1) {
         perm[n - 2] = nums[k] + '0';
         nums.erase(nums.begin() + k);
       }
         perm[n - 1] = nums[0] + '0';

       nums.clear();
       string s = string(perm.begin(), perm.end());
       perm.clear();
       return s;
    }
};
