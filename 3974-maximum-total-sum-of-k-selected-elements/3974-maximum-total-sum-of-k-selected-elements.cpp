class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long sum = 0;
        sort(rbegin(nums), rend(nums));

        for (int i = 0; i < k; i++) {
            if (mul > 0) {
                sum += (long long)nums[i] * (long long)mul;
            } else {
                sum += nums[i];
            }
            mul--;
        }
        return sum;
    }
};