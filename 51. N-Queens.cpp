class Solution {
  public:
    vector<vector<string>> res;
    vector<string> ans;
    bool check(int x, int y, vector<int> &col, int n) {
        if (col[y])
            return false;
        int i, j;
        for (i = x - 1, j = y - 1; i >= 0 && y >= 0; i--, j--) {
            if (ans[i][j] == 'Q')
                return false;
        }
        for (i = x - 1, j = y + 1; i >= 0 && y < n; i--, j++) {
            if (ans[i][j] == 'Q')
                return false;
        }
        for (i = x + 1, j = y + 1; i < n && y < n; i++, j++) {
            if (ans[i][j] == 'Q')
                return false;
        }
        for (i = x + 1, j = y - 1; i < n && y >= 0; i++, j--) {
            if (ans[i][j] == 'Q')
                return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        ans = vector<string>(n, string(n, '.'));
        vector<int> col(n, 0);
        dfs(0, col, n);
        return res;
    }

    void dfs(int row, vector<int> &col, int n) {
        if (row >= n) {
            res.push_back(ans);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(row, i, col, n)) {
                col[i] = 1;
                ans[row][i] = 'Q';
                dfs(row + 1, col, n);
                col[i] = 0;
                ans[row][i] = '.';
            }
        }
    }
};
