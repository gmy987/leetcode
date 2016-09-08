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
    ListNode* removeElements(ListNode* head, int val) {
		ListNode* pre = NULL, *cur = head;
		while(cur) {
			if(cur->val == val) {
				if(!pre) head = cur->next;
				else pre->next = cur->next;
			} else {
				pre = cur;
			}
			cur = cur->next;
		}
		return head;
    }
};
