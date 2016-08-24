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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        if (!root)
            return ans;
        vector<int> res;
        TreeNode *u;
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            res.clear();
            while (!s1.empty()) {
                u = s1.top();
                s1.pop();
                res.push_back(u->val);
                if (u->left)
                    s2.push(u->left);
                if (u->right)
                    s2.push(u->right);
            }
            ans.push_back(res);
            res.clear();
            if (s2.empty())
                break;
            while (!s2.empty()) {
                u = s2.top();
                s2.pop();
                res.push_back(u->val);
                if (u->right)
                    s1.push(u->right);
                if (u->left)
                    s1.push(u->left);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
