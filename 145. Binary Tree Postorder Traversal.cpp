/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursion Solution
class Solution {
  public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode *root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode *root) {
        if (!root)
            return;
        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);
    }
};

// Iterative Solution
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode *> st;
        TreeNode *tmp;
        st.push(root);
        while (!st.empty()) {
            tmp = st.top();
            st.pop();
            res.push_back(tmp->val);
            if (tmp->left)
                st.push(tmp->left);
            if (tmp->right)
                st.push(tmp->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
