class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp;

        if (nums.size() != n + 1) {
            return false;
        }

        for (auto& i : nums) {
            mp[i]++;
        }

        for (int i = 1; i < n; i++) {
            if (mp[i] != 1) {
                return false;
            }
        }

        if (mp[n] != 2) {
            return false;
        }
        return true;
    }
};