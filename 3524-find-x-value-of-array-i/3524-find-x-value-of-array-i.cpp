class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int rem = num % k;

            vector<long long> next(k, 0);
            next[rem]++;

            for (int r = 0; r < k; r++) {
                int newRem = (1LL * r * rem) % k;
                next[newRem] += dp[r];
            }

            dp = move(next);
            for (int r = 0; r < k; r++) res[r] += dp[r];
        }
        return res;
    }
};
