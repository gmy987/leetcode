class Solution {
  public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int> &nums) {
        dfs(0, nums);
        return res;
    }
    void dfs(int pos, vector<int> &nums) {
        if (pos >= nums.size()) {
            res.push_back(nums);
            return;
        }
        dfs(pos + 1, nums);
        for (int i = pos + 1; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            dfs(pos + 1, nums);
            swap(nums[i], nums[pos]);
        }
    }
};
