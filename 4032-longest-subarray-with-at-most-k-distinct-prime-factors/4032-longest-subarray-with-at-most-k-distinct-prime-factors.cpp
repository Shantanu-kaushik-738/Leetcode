class Solution {
public:
    vector<int> prime(int n) {
        vector<int> res;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                res.push_back(i);
                while (n % i == 0) n /= i; // skip the same factor
            }
        }
        if (n > 1) res.push_back(n);
        return res;
    }

    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0, res = 0, dis = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (auto& j : prime(nums[i])) { // find prime fect.
                if (!mp[j]) dis++;
                mp[j]++;
            }

            while (dis > k) { // invalid ele.
                for (auto& j : prime(nums[l])) {
                    mp[j]--;
                    if (!mp[j]) dis--;
                }
                l++;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};