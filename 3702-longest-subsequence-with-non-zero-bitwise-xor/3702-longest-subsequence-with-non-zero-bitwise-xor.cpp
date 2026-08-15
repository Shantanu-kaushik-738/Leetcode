class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool zero = true;
        for (auto& i : nums) {
            xr ^= i;
            if (i) zero = false;
        }
        if (zero) return 0;
        return xr == 0 ? nums.size() - 1 : nums.size();
    }
};
