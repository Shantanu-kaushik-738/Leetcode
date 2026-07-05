class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int res = -1e9;

        for (int i = 1; i < n; i++) {
            res = max(res, abs(nums[i] - nums[i - 1]));
        }
        return max(res, abs(nums[0] - nums[n - 1]));
    }
};