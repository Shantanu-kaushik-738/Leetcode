class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int res = 1e9;
        for (int i = 0; i < nums.size() - 1; i += 2) {
            res = min(res, stoi(to_string(nums[i]) + to_string(nums[i + 1])));
        }
        return res;
    }
};
