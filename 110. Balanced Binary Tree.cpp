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
    int dep;
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        int left = dfs(root->left);
        int right = dfs(root->right);
        return isBalanced(root->left) && isBalanced(root->right) &&
               abs(left - right) <= 1;
    }

    int dfs(TreeNode *root) {
        if (!root)
            return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
};
