class Solution {
private:
    void helper(vector<int>& nums, vector<int>& arr, int idx, vector<vector<int>>& res) {
        
        res.push_back(arr);
        for (int i = idx; i < nums.size(); i++) {  // find subsets using loop first element subsets then second element ........ and so on
            if (i > idx && nums[i] == nums[i - 1]) continue;

            arr.push_back(nums[i]);
            helper(nums, arr, i + 1, res);
            arr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> res;
        
        sort(begin(nums), end(nums));
        helper(nums, arr, 0, res);
        return res;
    }
};