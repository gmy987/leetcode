class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		int len = candidates.size();
		sort(candidates.begin(),candidates.end());
		vector<vector<int>> res;
		if(!len) return res;
		vector<int> ans;
		dfs(candidates,res,ans,len,target,0);
		return res;
    }
	void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& ans,
			 int n, int target, int pos) {
		if(target<0) return;
		if(target==0) {
			res.push_back(ans);
			return;
		}
		if(pos>=n) return;
		for( int i = pos ; i < n ; i++ ) {
			if(i!=pos&&nums[i]==nums[i-1]) continue;
			ans.push_back(nums[i]);
			dfs(nums,res,ans,n,target-nums[i],i);
			ans.pop_back();
		}
	}
};
