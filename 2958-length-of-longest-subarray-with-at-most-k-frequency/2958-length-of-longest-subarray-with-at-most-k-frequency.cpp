class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        int l = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;
            while (mp[nums[r]] > k) mp[nums[l++]]--;
            res = max(res, r - l + 1);
        }
        return res;
    }
};