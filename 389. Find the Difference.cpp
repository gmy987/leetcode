class Solution {
  public:
    char findTheDifference(string s, string t) {
        int len = s.length();
        char res = t[len];
        for (int i = 0; i < len; i++)
            res ^= s[i] ^ t[i];
        return res;
    }
};
