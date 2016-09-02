class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int,int> m;
		int len = nums.size();
		vector<vector<int>> bucket(len+1);
		vector<int> ans;
		for( int i = 0 ; i < len ; i++ ) m[nums[i]]++;
		for( auto mm : m ) {
			bucket[mm.second].push_back(mm.first);
		}
		for( int i = len ; i > 0 ; i-- ) {
			for( int j = bucket[i].size()-1 ; j >= 0 ; j-- ) {
				ans.push_back(bucket[i][j]);
				k--;
				if(!k) return ans;
			}
		}
		return ans;
    }
};
