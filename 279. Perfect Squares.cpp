class Solution {
public:
    int numSquares(int n) {
		vector<int> dp(n+1);
		dp[0] = 0;
		int tmp;
		for( int i = 1; i <=n ; i++ ) {
			tmp = INT_MAX;
			for( int j = 1 ; j*j <= i ; j++ ) {
				tmp = min(tmp,dp[i-j*j]+1);
			}
			dp[i] = tmp;
		}
		return dp[n];
    }
};
