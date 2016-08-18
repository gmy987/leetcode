/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  private:
    ListNode *root;

  public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least
       one node. */
    Solution(ListNode *head) { root = head; }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *tmp = root;
        int cnt = 1, ans;
        while (tmp) {
            if (rand() % cnt == 0)
                ans = tmp->val;
            cnt++;
            tmp = tmp->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
