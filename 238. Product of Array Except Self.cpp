class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> output(len, 1);
        output[0] = 1;
        for (int i = 1; i < len; i++) {
            output[i] = output[i - 1] * nums[i - 1];
        }
        int product = nums[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            output[i] *= product;
            product *= nums[i];
        }
        return output;
    }
};
