class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        int len = nums.size();
        return quickSort(0, len - 1, nums, len, k);
    }

    int quickSort(int low, int high, vector<int> &nums, int len, int k) {
        if (low < high) {
            int i = low, j = high, p = nums[low];
            while (i < j) {
                while (i < j && nums[j] >= p)
                    j--;
                nums[i] = nums[j];
                while (i < j && nums[i] <= p)
                    i++;
                nums[j] = nums[i];
            }
            nums[i] = p;
            if (i == len - k)
                return p;
            else if (i > len - k)
                return quickSort(low, i - 1, nums, len, k);
            else
                return quickSort(i + 1, high, nums, len, k);
        }
        return nums[low];
    }
};
