class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (!n)
            return;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
            }
        }
    }
};
