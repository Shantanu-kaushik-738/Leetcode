class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxs = INT_MIN;
        int curs = 0;
        for (int i = 0; i < n; i++) {
            curs += nums[i];
            maxs = max(maxs, curs);
            if (curs < 0) {
                curs = 0;
            }
        }
        return maxs;
    }
};