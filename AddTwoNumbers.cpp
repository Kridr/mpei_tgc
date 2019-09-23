//https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *elem  = NULL;
        int carry = 0;
        while (l1 || l2) {
            //make it zero if we reached the end
            int v1 = l1 ? l1 -> val : 0;
            int v2 = l2 ? l2 -> val : 0;

            //we want to split: *x and x*
            int tmp = v1 + v2 + carry;

            //our excess
            carry = tmp / 10;
            //valuable part
            int value = tmp % 10;

            //create elem in list
            ListNode* current = new ListNode(value);

            //create begginning if it hadn't made
            if (!head)
                head = current;

            //make ref from elem to current
            if (elem)
                elem -> next = current;

            //overriding our elem
            elem = current;

            //make l1 and l2 up-to-date
            l1 = l1 ? l1 -> next : NULL;
            l2 = l2 ? l2 -> next : NULL;
        }

        //left number
        if (carry > 0) {
            ListNode* resl = new ListNode(carry);
            elem -> next  = resl;
        }

        return head;
    }
};
