class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);
        int len1 = ransomNote.length(), len2 = magazine.length();
        for (int i = 0; i < len2; i++)
            cnt[magazine[i] - 'a']++;
        for (int i = 0; i < len1; i++)
            if (--cnt[ransomNote[i] - 'a'] < 0)
                return false;
        return true;
    }
};
