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
    struct Node {
        TreeNode *t;
        int depth;
    };
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        queue<Node> q;
        Node u, v;
        u.t = root;
        u.depth = 1;
        q.push(u);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            if (!u.t->left && !u.t->right)
                return u.depth;
            if (u.t->left) {
                v.t = u.t->left;
                v.depth = u.depth + 1;
                q.push(v);
            }
            if (u.t->right) {
                v.t = u.t->right;
                v.depth = u.depth + 1;
                q.push(v);
            }
        }
        return 0;
    }
};
