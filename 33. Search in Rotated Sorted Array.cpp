class Solution {
public:
    int search(vector<int>& nums, int target) {
		int len = nums.size();
		int low = 0, high = len-1, mid;
		while(low<high) {
			mid = low+(high-low>>1);
			if(nums[mid]>nums[high]) low = mid+1;
			else high = mid;
		}
		int rot = low,rmid;
		low = 0, high = len-1;
		while(low<high) {
			mid = low+(high-low>>1);
			rmid = (mid+rot)%len;
			if(nums[rmid]==target) return rmid;
			else if(nums[rmid]>target) high = mid-1;
			else low = mid+1;
		}
		return -1;
    }
};
