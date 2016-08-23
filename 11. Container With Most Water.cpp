class Solution {
  public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1, res = 0;
        while (i < j)
            res = max(res, (j - i) * height[height[i] < height[j] ? i++ : j--]);
        return res;
    }
};
