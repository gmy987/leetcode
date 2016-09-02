class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(!matrix.size()) return false;
		int row = SearchRow(target,matrix);
		if(row==-2) return true;
		else if(row==-1) return false;
		else return SearchCol(target,matrix,row);
    }
	bool SearchCol(int target, vector<vector<int>>& matrix, int row) {
		int low = 0, high = matrix[0].size()-1, m;
		while(low<=high) {
			m = low+(high-low>>1);
			if(matrix[row][m]==target) return true;
			else if(matrix[row][m]>target) high = m-1;
			else low = m+1;
		}
		return false;
	}
	int SearchRow(int target, vector<vector<int>>& matrix) {
		int low = 0, high = matrix.size()-1, m;
		while(low<=high) {
			m = low+(high-low>>1);
			if(matrix[m][0]==target) return -2;
			else if(matrix[m][0]>target) high = m-1;
			else low = m+1;
		}
		return low-1;
	}
};
