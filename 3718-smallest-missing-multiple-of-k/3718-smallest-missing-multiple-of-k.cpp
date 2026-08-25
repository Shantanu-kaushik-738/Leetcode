class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto& i : nums) {
            if (!(i % k)) mp[i / k]++;
        }
        int res = 1;
        while (1) {
            if (!mp[res]) return res * k;
            res++;
        }
        return k;
    }
};
