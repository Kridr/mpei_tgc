//https://leetcode.com/problems/next-greater-node-in-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
      vector<int> res, stack;

      for (ListNode* p = head; p != nullptr; p = p->next)
          res.push_back(p -> val);

      for (int i = res.size() - 1; i >= 0; --i) {
        int val = res[i];

        //hella lit
        while (!stack.empty() && stack.back() <= res[i])
            stack.pop_back();

        res[i] = stack.empty() ? 0 : stack.back();

        stack.push_back(val);
      }
      return res;
    }
};
