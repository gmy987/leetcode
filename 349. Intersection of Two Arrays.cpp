class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size(), len2 = nums2.size(), i, j;
        vector<int> ans;
        for (i = 0; i < len1; i++) {
            if (i && nums1[i] == nums1[i - 1])
                continue;
            if (binarySearch(nums2, nums1[i], 0, len2 - 1))
                ans.push_back(nums1[i]);
        }
        sort(ans.begin(), ans.end());
        vector<int>::iterator it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());

        return ans;
    }

    bool binarySearch(vector<int> &nums, int target, int low, int high) {
        int mid;
        while (low <= high) {
            mid = low + (high - low >> 1);
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};
