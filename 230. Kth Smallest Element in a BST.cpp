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
    int kthSmallest(TreeNode* root, int k) {
		int cnt = dfs(root->left);
		if(k == cnt+1) {
			return root->val;
		} else if(k<cnt+1) {
			return kthSmallest(root->left,k);
		} else return kthSmallest(root->right, k-cnt-1);
    }
	int dfs(TreeNode* root) {
		if(!root) return 0;
		return 1+dfs(root->left)+dfs(root->right);
	}
};
