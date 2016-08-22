class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        int cnt1 = 0, cnt2 = 0, res1 = INT_MAX, res2 = INT_MAX;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (!cnt1 &&
                ((res2 != INT_MAX && res2 != nums[i]) || res2 == INT_MAX)) {
                cnt1 = 1;
                res1 = nums[i];
            } else if (!cnt2 && ((res1 != INT_MAX && res1 != nums[i]) ||
                                 res1 == INT_MAX)) {
                cnt2 = 1;
                res2 = nums[i];
            } else if (nums[i] == res1) {
                cnt1++;
            } else if (nums[i] == res2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            if (res1 == nums[i])
                cnt1++;
            else if (res2 == nums[i])
                cnt2++;
        }
        if (cnt1 > len / 3)
            ans.push_back(res1);
        if (cnt2 > len / 3)
            ans.push_back(res2);
        return ans;
    }
};
