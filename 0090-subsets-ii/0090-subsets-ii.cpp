class Solution {
private:
    void helper(vector<int>& nums, vector<int>& ans, int i,
                vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        helper(nums, ans, i + 1, res);

        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        ans.pop_back();
        helper(nums, ans, idx, res);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        sort(begin(nums), end(nums));

        helper(nums, ans, 0, res);
        return res;
    }
};