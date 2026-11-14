class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = 1e9;
        for (int i = 0; i < nums.size(); i++) {
            int s = 0;
            for (int j = i; j < nums.size(); j++) {
                s += nums[j];
                if ((j - i + 1) >= l && (j - i + 1) <= r && s > 0) ans = min(ans, s);
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};
