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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *u;
        while (!q.empty()) {
            res.clear();
            for (int i = q.size(); i > 0; i--) {
                u = q.front();
                q.pop();
                res.push_back(u->val);
                if (u->left)
                    q.push(u->left);
                if (u->right)
                    q.push(u->right);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
