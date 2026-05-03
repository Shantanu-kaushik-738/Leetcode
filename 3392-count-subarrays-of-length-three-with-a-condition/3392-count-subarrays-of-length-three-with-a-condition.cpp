class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i <= n - 3; i++) {
            int f = nums[i];
            int t = nums[i + 2];
            int m = nums[i + 1];
            if (f + t == (double)m / 2.0) {
                cnt++;
            }
        }
        return cnt;
    }
};
