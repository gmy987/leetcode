class Solution {
  public:
    int hammingWeight(uint32_t n) {
        int ans = n ? 1 : 0;
        while (n & (n - 1))
            ans++;
        return ans;
    }
};
