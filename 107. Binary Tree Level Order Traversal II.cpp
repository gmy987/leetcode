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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		vector<int> ans;
		if(!root) return res;
		queue<TreeNode*> q;
		TreeNode* u;
		q.push(root);
		while(!q.empty()) {
			ans.clear();
			for( int i = q.size() ; i > 0 ; i-- ) {
				u = q.front();
				q.pop();
				ans.push_back(u->val);
				if(u->left) q.push(u->left);
				if(u->right) q.push(u->right);
			}
			res.push_back(ans);
		}
		reverse(res.begin(),res.end());
		return res;
    }
};
