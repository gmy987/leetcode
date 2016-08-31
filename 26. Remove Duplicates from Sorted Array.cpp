class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int cnt = 0, len = nums.size();
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1])
                cnt++;
            else
                nums[i - cnt] = nums[i];
        }
        return len - cnt;
    }
};
