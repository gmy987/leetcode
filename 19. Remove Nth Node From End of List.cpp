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
    int i = 0;
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head)
            return NULL;
        head->next = removeNthFromEnd(head->next, n);
        i++;
        return i == n ? head->next : head;
    }
};
