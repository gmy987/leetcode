class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int res = 0, minp = INT_MAX, len = prices.size();
        for (int i = 0; i < len; i++) {
            minp = min(minp, prices[i]);
            res = max(res, prices[i] - minp);
        }
        return res;
    }
};
