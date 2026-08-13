class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int l = 0, r = 0, zero = 0;

        while (r < nums.size()) {
            if (!nums[r]) zero++;
            if (zero > k) {
                if (!nums[l]) zero--;
                l++;
            }
            if (zero <= k) res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
