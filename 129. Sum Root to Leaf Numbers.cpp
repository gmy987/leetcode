/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    void dfs(TreeNode *root, int cur, int &sum) {
        if (!root->left && !root->right) {
            cur = cur * 10 + root->val;
            sum += cur;
            return;
        }
        if (root->left)
            dfs(root->left, cur * 10 + root->val, sum);
        if (root->right)
            dfs(root->right, cur * 10 + root->val, sum);
    }
};
