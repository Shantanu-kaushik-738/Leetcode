class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        nums.push_back(lower - 1);
        nums.push_back(upper + 1);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 1; i < n; i++) {
            if (nums[i] < lower || nums[i - 1] > upper) continue;
            if (nums[i] - nums[i - 1] - 1 > 0) ans.push_back({nums[i - 1] + 1, nums[i] - 1});
        }
        return ans;
    }
};
