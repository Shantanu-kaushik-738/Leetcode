class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i <= nums.size() - k; i++) {
            for (int j = i; j < i + k; j++) {
                mp[nums[j]].insert(i);
            }
        }

        int res = -1;
        for (auto& i : mp) {
            if (i.second.size() == 1) res = max(res, i.first);
        }
        return res;
    }
};