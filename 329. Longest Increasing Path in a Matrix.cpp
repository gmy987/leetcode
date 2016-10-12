class Solution {
private:
	int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
	int n,m;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
		n = matrix.size();
		if(!n) return 0;
		m = matrix[0].size();
		vector<vector<int>> record(n,vector<int>(m,0));
		int res = 0,tmp;
		for( int i = 0 ; i < n ; i++ ) {
			for( int j = 0 ; j < m ; j++ ) {
				tmp = dfs(i,j,matrix,record);
				res = max(tmp,res);
			}
		}
		return res;
    }
	int dfs( int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& record) {
		if(record[x][y]) return record[x][y];
		int ma = 1;
		for( int i = 0 ; i < 4 ; i++ ) {
			int ax = x+dir[i][0], ay = y+dir[i][1];
			if(ax>=0&&ay>=0&&ax<n&&ay<m&&matrix[ax][ay]>matrix[x][y]) {
				int tmp = dfs(ax,ay,matrix,record)+1;
				ma = max(ma,tmp);
			}
		}
		record[x][y] = ma;
		return ma;
	}
};
