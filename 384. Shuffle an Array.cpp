class Solution {
  private:
    vector<int> arr;

  public:
    Solution(vector<int> nums) { arr = vector<int>(nums); }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { return arr; }

    /** Returns a random shuffling of the array. */
    /**
    for the first one it has n choice, and the second n-1 choice...
    the total probability is n*(n-1)*(n-2)*...*1,
    which the total permutation is n!
    **/
    vector<int> shuffle() {
        vector<int> ans(arr);
        int len = arr.size();
        srand(time(NULL));
        for (int i = len - 1; i >= 0; i++) {
            swap(ans[i], ans[rand() % (i + 1)]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
