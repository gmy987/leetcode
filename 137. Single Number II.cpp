class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int len = nums.size(), tmp, sum, res = 0;
        int i, j;
        for (i = 0; i < 32; i++) {
            tmp = 1 << i;
            sum = 0;
            for (j = 0; j < len; j++) {
                if (tmp & nums[j])
                    sum++;
            }
            if (sum % 3)
                res += tmp;
        }
        return res;
    }
};
