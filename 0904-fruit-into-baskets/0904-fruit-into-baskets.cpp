class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int res = 0;
        int l = 0, r = 0;
        unordered_map<int, int>mp;

        while (r < nums.size()) {
            mp[nums[r]]++;

            if (mp.size() > 2) {
                while (mp.size() > 2) {
                    mp[nums[l]]--;
                    if (!mp[nums[l]]) mp.erase(nums[l]);
                    l++;
                }
            }
            if (mp.size() <= 2) res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};