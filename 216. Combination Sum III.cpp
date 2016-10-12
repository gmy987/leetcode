class Solution {
private:
	vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> ans;
		dfs(1,ans,k,n);
		return res;
    }
	void dfs(int pos, vector<int>& ans, int k, int n) {
		if(ans.size()==k&&n==0) {
			res.push_back(ans);
			return;
		}
		if(ans.size()>k||n<0||pos>9) return;
		for( int i = pos ; i <= 9 ; i++ ) {
			ans.push_back(i);
			dfs(i+1,ans,k,n-i);
			ans.pop_back();
		}
	}
};
