class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int s = 1 << nums.size();
        for (int i = 0; i < s; i++) {
            vector<int> res;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) res.push_back(nums[j]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};