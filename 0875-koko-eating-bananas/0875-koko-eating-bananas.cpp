class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size();
        long l = 1, r = *max_element(begin(nums), end(nums));
        int ans = r;

        while (l <= r) {
            int m = l + (r - l) / 2;
            long k = 0;
            for (int i = 0; i < n; i++) k += ceil(double(nums[i]) / double(m));
            if (k <= h) ans = m, r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};
