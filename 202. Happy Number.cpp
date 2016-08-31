class Solution {
  public:
    bool isHappy(int n) {
        int res;
        while (true) {
            res = 0;
            for (; n; n /= 10)
                res += (n % 10) * (n % 10);
            n = res;
            if (n == 4)
                return false;
            if (n == 1)
                return true;
        }
    }
};
