class Solution {
  public:
    int maxProduct(vector<string> &words) {
        int len = words.size(), i, j, l;
        vector<int> bitmap(len, 0);
        for (i = 0; i < len; i++) {
            l = words[i].length();
            for (j = 0; j < l; j++)
                bitmap[i] |= 1 << (words[i][j] - 'a');
        }
        int res = 0;
        for (i = 0; i < len - 1; i++) {
            for (j = i + 1; j < len; j++) {
                if (!(bitmap[i] & bitmap[j])) {
                    l = words[i].length() * words[j].length();
                    res = max(res, l);
                }
            }
        }
        return res;
    }
};
