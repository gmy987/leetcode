/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS Solution
class Solution {
  public:
    vector<int> res;
    vector<int> rightSideView(TreeNode *root) {
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode *root, int depth) {
        if (!root)
            return;
        if (res.size() <= depth)
            res.push_back(root->val);
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }
};

// BFS Solution
class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *tmp;
        while (!q.empty()) {
            tmp = q.front();
            res.push_back(tmp->val);
            for (int i = q.size(); i > 0; i--) {
                tmp = q.front();
                q.pop();
                if (tmp->right)
                    q.push(tmp->right);
                if (tmp->left)
                    q.push(tmp->left);
            }
        }
        return res;
    }
};
