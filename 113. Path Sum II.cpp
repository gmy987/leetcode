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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> ans;
        dfs(root, res, ans, 0, sum);
        return res;
    }
    void dfs(TreeNode *root, vector<vector<int>> &res, vector<int> &ans,
             int cur, int &sum) {
        if (!root->left && !root->right) {
            cur += root->val;
            if (cur == sum) {
                ans.push_back(root->val);
                res.push_back(ans);
                ans.pop_back();
                return;
            }
        }
        ans.push_back(root->val);
        if (root->left)
            dfs(root->left, res, ans, cur + root->val, sum);
        if (root->right)
            dfs(root->right, res, ans, cur + root->val, sum);
        ans.pop_back();
    }
};
