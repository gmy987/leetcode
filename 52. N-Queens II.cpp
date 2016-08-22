class Solution {
  public:
    int res;
    bool check(int x, int y, vector<int> &col, vector<vector<int>> &vis,
               int n) {
        if (col[y])
            return false;
        int i, j;
        for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (vis[i][j])
                return false;
        }
        for (i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
            if (vis[i][j])
                return false;
        }
        for (i = x + 1, j = y + 1; i < n && j < n; i++, j++) {
            if (vis[i][j])
                return false;
        }
        for (i = x + 1, j = y - 1; i < n && j >= 0; i++, j--) {
            if (vis[i][j])
                return false;
        }
        return true;
    }
    int totalNQueens(int n) {
        res = 0;
        vector<int> col(n, 0);
        vector<vector<int>> vis(n, vector<int>(n, 0));
        dfs(0, col, vis, n);
        return res;
    }

    void dfs(int row, vector<int> &col, vector<vector<int>> &vis, int n) {
        if (row >= n) {
            res++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(row, i, col, vis, n)) {
                col[i] = 1;
                vis[row][i] = 1;
                dfs(row + 1, col, vis, n);
                col[i] = 0;
                vis[row][i] = 0;
            }
        }
    }
};
