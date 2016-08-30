// O(n)
class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        int len = nums.size();
        if (!len)
            return 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] >= target)
                return i;
        }
        return len - 1;
    }
};

// Binary Search O(logn)
class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = low + high >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
