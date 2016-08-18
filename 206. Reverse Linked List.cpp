/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Iterative method
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *cur = head->next, *tmp;
        head->next = NULL;
        while (cur) {
            tmp = cur->next;
            cur->next = head;
            head = cur;
            cur = tmp;
        }
        return head;
    }
};

// Recursive method
/**
 * class Solution {
 * public:
 * 	ListNode* reverseList(ListNode* head) {
 * 		return dfs(head,NULL);
 * 	}
 *
 * 	ListNode* dfs(ListNode* cur, ListNode* prev) {
 * 		if(!cur) return prev;
 * 		ListNode* tmp = cur->next;
 * 		cur->next = prev;
 * 		return dfs(tmp,current);
 * 	}
 * }
 */
