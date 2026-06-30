class Solution {
public:
    void cs(vector<int> nums, int i, vector<int>& arr, vector<vector<int>>& ans, int k) {
        if (k == 0) {
            ans.push_back(arr);
            return;
        }

        for (int j = i; j < nums.size();
             j++) { // loop for possible combination subsequences
            if (j > i && nums[j] == nums[j - 1]) continue; // out of bound or same element

            if (nums[j] > k) break; // target reached
            arr.push_back(nums[j]); // store current element

            cs(nums, j + 1, arr, ans, k - nums[j]);
            arr.pop_back(); // backtrack for next element
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> arr;

        sort(begin(nums), end(nums));
        cs(nums, 0, arr, ans, k);
        return ans;
    }
};