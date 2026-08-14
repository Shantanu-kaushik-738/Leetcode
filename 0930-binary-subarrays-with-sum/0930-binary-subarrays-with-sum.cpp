class Solution {
public:
    int funx(vector<int> nums, int goal) {
        if (goal < 0) return 0;
        int res = 0;
        int l = 0, r = 0, sum = 0;

        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal) sum -= nums[l++];
            res += r - l + 1;
            r++;
        }
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return funx(nums, goal) - funx(nums, goal - 1);
    }
};
