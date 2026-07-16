class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];

        for (auto& i : nums) {
            mx = max(mx, i);
            i = gcd(i, mx);
        }

        sort(begin(nums), end(nums));
        long long res = 0;
        int i = 0, j = n - 1;

        while (i < j) {
            res += gcd(nums[i++], nums[j--]);
        }
        return res;
    }
};