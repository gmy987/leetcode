class Solution {
  public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (!n)
            return 0;
        for (int i = 1; i <= n / 2; i++) {
            if (nums[i] < nums[i - 1])
                return nums[i];
            if (nums[n - i] < nums[n - i - 1])
                return nums[n - i];
        }
        return nums[0];
    }
};
