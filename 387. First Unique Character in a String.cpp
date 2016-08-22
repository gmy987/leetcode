class Solution {
  public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> ch(26);
        int len = s.length();
        for (int i = 0; i < len; i++) {
            ch[s[i] - 'a'].first++;
            ch[s[i] - 'a'].second = i;
        }
        int res = len;
        for (int i = 0; i < 26; i++) {
            if (ch[i].first == 1)
                res = min(res, ch[i].second);
        }
        return res == len ? -1 : res;
    }
};
