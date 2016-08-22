class Solution {
  public:
    int countNumbersWithUniqueDigits(int n) {
        if (!n)
            return 1;
        int res = 10;
        int mul = 9;
        int k = 9;
        for (int i = 2; i <= n; i++) {
            if (n > 10)
                break;
            mul *= k;
            res += mul;
            k--;
        }
        return res;
    }
};
