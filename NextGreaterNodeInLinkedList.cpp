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
        vector <int> res;
        ListNode* root = head;

        for(ListNode* root = head; root; root = root -> next) {
            res.push_back(root -> val);
        }

        int sz = res.size();

        for(int i = 0; i < sz - 1; i++) {
            int j = i + 1;
            bool con = true;
            while (con & j < sz) {
                if (res[j] > res[i]) {
                    res[i] = res[j];
                    con = false;
                }
                j++;
            }
            if (con) {
                res[i] = 0;
            }
        }

        res[sz - 1] = 0;

        return res;
    }
};
