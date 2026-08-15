class Solution {
public:
    int funx(vector<int> nums, int k) {
        if (k < 0) return 0;
        int res = 0;
        int l = 0, r = 0, sum = 0;

        while (r < nums.size()) {
            sum += nums[r] % 2;
            while (sum > k) sum -= nums[l++] % 2;
            res += r - l + 1;
            r++;
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return funx(nums, k) - funx(nums, k - 1);    
    }
};
