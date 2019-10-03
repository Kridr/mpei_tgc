//https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);
        int size = 0;

        for (ListNode* node = root; node; node = node -> next) {
            size++;
        }


        vector <int> szv(k);


        int tk = k;
        for (int i = 0; i < k; i++) {
            szv[k - i - 1] = size / tk;
            size = (size / tk == 0) ? size : size - size / tk;
            tk--;
        }
        ListNode* node = root, *prev = nullptr;
        for (int i = 0; node && i < k; i++) {
            parts[i] = node;
            for (int j = 0; j < szv[i]; j++) {
                prev = node;
                node = node -> next;
            }
            prev->next = nullptr;
        }

        szv.clear();
        return parts;
    }
};
