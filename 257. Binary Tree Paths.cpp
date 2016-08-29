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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        if (!root)
            return res;
        string ans = "";
        dfs(root, res, ans);
        return res;
    }
    void dfs(TreeNode *root, vector<string> &res, string ans) {
        if (!root->left && !root->right) {
            res.push_back(ans + to_string(root->val));
            return;
        }
        if (root->left)
            dfs(root->left, res, ans + to_string(root->val) + "->");
        if (root->right)
            dfs(root->right, res, ans + to_string(root->val) + "->");
    }
};
