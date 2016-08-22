class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int len = nums.size();
        int cnt = 0, res;
        for (int i = 0; i < len; i++) {
            if (!cnt) {
                cnt = 1;
                res = nums[i];
            } else if (nums[i] != res) {
                cnt--;
            } else if (nums[i] == res) {
                cnt++;
            }
        }
        return res;
    }
};
