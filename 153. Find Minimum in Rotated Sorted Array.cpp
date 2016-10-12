class Solution {
  public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (!n)
            return 0;
        int low = 0, high = n - 1, mid;
        while (low < high) {
            mid = low + high >> 1;
            if (nums[mid] < nums[high])
                high = mid;
            else
                low = mid + 1;
        }
        return nums[low];
    }
};
