class Solution {
public:
    void cs(vector<int> nums, int i, vector<int> arr, vector<vector<int>>& ans, int k) {

        if (i == nums.size() || k < 0) {
            return;
        }

        if (k == 0) {
            ans.push_back(arr);
            return;
        }

        arr.push_back(nums[i]);
        cs(nums, i, arr, ans, k - nums[i]); // inclusion

        arr.pop_back();
        cs(nums, i + 1, arr, ans, k); // exclusion
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> arr;

        cs(nums, 0, arr, ans, k);
        return ans;
    }
};