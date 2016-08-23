class Solution {
  public:
    bool isPowerOfThree(int n) {
        if (!n)
            return false;
        return pow(3, (int)(log(n) / log(3) + 0.5)) == n;
    }
};
