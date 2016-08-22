class Solution {
  public:
    int titleToNumber(string s) {
        int power = 1;
        int len = s.length();
        int res = 0;
        for (int i = len - 1; i >= 0; i--) {
            res += power * (s[i] - 'A' + 1);
            power *= 26;
        }
        return res;
    }
};
