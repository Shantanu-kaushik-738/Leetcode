class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        long long sum = n*(n + 1) / 2;
        long long ns = 0;

        for (int i = 0; i < n; i++) {
            ns += nums[i];
        }
        return sum - ns;
    }
};