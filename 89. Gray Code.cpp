class Solution {
  public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (!n)
            return res;
        res.push_back(0);
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(res[j] | cnt);
            }
            cnt <<= 1;
        }
        return res;
    }
};
