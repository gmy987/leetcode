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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == p || root == q)
            return root;
        bool pl = dfs(root->left, p);
        bool ql = dfs(root->left, q);
        if (pl != ql)
            return root;
        else if (pl && ql)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }

    bool dfs(TreeNode *root, TreeNode *p) {
        if (root == p)
            return true;
        else if (!root)
            return false;
        else
            return dfs(root->left, p) || dfs(root->right, p);
    }
};
