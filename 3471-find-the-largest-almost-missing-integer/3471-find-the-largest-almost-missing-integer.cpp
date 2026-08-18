class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> frq;
        for (int i = 0; i <= nums.size() - k; i++) {
            unordered_map<int, bool> sn;
            for (int j = i; j < i + k; j++) {
                if (!sn[nums[j]]) {
                    frq[nums[j]]++;
                    sn[nums[j]] = true;
                }
            }
        }

        int res = -1;
        for (auto& p : frq) {
            if (p.second == 1) res = max(res, p.first);
        }
        return res;
    }
};
