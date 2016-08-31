class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (!numRows)
            return res;
        vector<int> ans;
        ans.push_back(1);
        res.push_back(ans);
        for (int i = 2; i <= numRows; i++) {
            ans.clear();
            ans.push_back(1);
            for (int j = 0; j < i - 2; j++) {
                ans.push_back(res[i - 2][j] + res[i - 2][j + 1]);
            }
            ans.push_back(1);
            res.push_back(ans);
        }
        return res;
    }
};
