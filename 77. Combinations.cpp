class Solution {
  public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        dfs(1, 0, ans, n, k);
        return res;
    }
    void dfs(int pos, int len, vector<int> &ans, int n, int k) {
        if (len == k) {
            res.push_back(ans);
            return;
        }
        if (pos > n)
            return;
        if (n - pos + 1 < k - len)
            return;
        for (int i = pos; i <= n; i++) {
            ans.push_back(i);
            dfs(i + 1, len + 1, ans, n, k);
            ans.pop_back();
        }
    }
};
