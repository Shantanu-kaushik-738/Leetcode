class Solution {
public:
    int funx(vector<int>& nums) {
        int n = nums.size();
        vector<int> pgcd(n, nums[0]), sgcd(n, nums[n - 1]);

        for (int i = 1; i < n; i++)
            pgcd[i] = gcd(pgcd[i - 1], nums[i]);

        for (int i = n - 2; i >= 0; i--)
            sgcd[i] = gcd(sgcd[i + 1], nums[i]);

        int res = 0;
        for (int i = 0; i < n - 1; i++)
            if (pgcd[i] == sgcd[i + 1]) res++;
        return res;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int res = funx(nums);

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if (i != j) temp.push_back(nums[j]);
            }
            res = max(res, funx(temp));
        }
        return res;
    }
};
