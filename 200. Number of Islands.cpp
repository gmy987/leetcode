class Solution {
  public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    struct Node {
        int x, y;
    };
    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        if (!n)
            return 0;
        int res = 0;
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    bfs(i, j, grid);
                }
            }
        }
        return res;
    }
    void bfs(int x, int y, vector<vector<char>> &grid) {
        Node u, v;
        u.x = x, u.y = y;
        queue<Node> q;
        q.push(u);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ax = u.x + dir[i][0], ay = u.y + dir[i][1];
                if (ax >= 0 && ay >= 0 && ax < n && ay < m &&
                    grid[ax][ay] == '1') {
                    grid[ax][ay] = '0';
                    v.x = ax;
                    v.y = ay;
                    q.push(v);
                }
            }
        }
    }
};
