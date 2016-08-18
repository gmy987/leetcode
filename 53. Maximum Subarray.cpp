class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int len = nums.size();
        if (!len)
            return 0;
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
