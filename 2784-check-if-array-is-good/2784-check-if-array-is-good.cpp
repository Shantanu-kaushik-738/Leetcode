class Solution {
public:
    bool isGood(vector<int>& nums) {
        int mxi = 0;
        unordered_map<int, int> mp;

        for (auto& i : nums) {
            mp[i]++;
            mxi = max(mxi, i);
        }

        for (int i = 1; i < nums.size(); i++) {
            if (mp[i] == 0) {
                return false;
            }
        }
        return mp[mxi] == 2 && nums.size() == mxi + 1;
    }
};
