/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(null) {}
 * };
 */
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return NULL;
        ListNode *fast = head->next->next, *slow = head->next;
        while (fast) {
            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
            if (!fast->next)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        return NULL;
    }
};
