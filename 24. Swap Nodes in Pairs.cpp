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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *nxt = head->next->next, *prev = head, *cur = head->next;
        head = cur;
        cur->next = prev;
        prev->next = nxt;
        cur = prev;
        prev = cur->next;
        while (prev && prev->next) {
            nxt = prev->next->next;
            cur->next = prev->next;
            cur->next->next = prev;
            prev->next = nxt;
            cur = prev;
            prev = nxt;
        }
        return head;
    }
};
