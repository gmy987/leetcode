class Solution {
private:
	vector<vector<int>> res;
	int n;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		n = candidates.size();
		if(!n) return res;
		vector<int> ans;
		sort(candidates.begin(),candidates.end());
		dfs(0,target,ans,candidates);
		return res;
    }
	void dfs(int pos, int target, vector<int>& ans, vector<int>& nums) {
		if(target==0) {
			res.push_back(ans);
			return;
		}
		if(target<0||pos>=n) return;
		for( int i = pos ; i < n ; i++ ) {
			if(i!=pos&&nums[i]==nums[i-1]) continue;
			ans.push_back(nums[i]);
			dfs(i+1,target-nums[i],ans,nums);
			ans.pop_back();
		}
	}
};
