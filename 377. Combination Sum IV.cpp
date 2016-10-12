class Solution {
private:
	int n;
	int res;
public:
    int combinationSum4(vector<int>& nums, int target) {
    	vector<int> dp(target+1,0);
		sort(nums.begin(),nums.end());
		dp[0] = 1;
		int len = nums.size();
		for( int i = 1 ; i <= target ; i++ ) {
			for( int j = 0 ; j < len && nums[j] <= i ; j++ ) {
				dp[i] += dp[i-nums[j]];
			}
		}
		return dp[target];
    }
};
