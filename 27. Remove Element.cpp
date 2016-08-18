class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0, len = nums.size(), j = len - 1;
        if (!len)
            return 0;
        while (i < j) {
            if (nums[j] == val)
                j--;
            else if (nums[i] == val) {
                swap(nums[i], nums[j]);
                j--;
            } else
                i++;
        }
        if (nums[i] == val)
            return i;
        return i + 1;
    }
};
