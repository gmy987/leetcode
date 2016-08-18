class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int len = nums.size();
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i]) {
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
    }
};
