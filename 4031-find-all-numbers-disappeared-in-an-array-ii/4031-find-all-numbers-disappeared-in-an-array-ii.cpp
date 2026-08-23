class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int l, int u) {
        vector<vector<int>> res;

        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums)); // remove duplicate el from nums

        vector<int> num;
        for (auto& i : nums) {
            if (i >= l && i <= u) num.push_back(i);
        }

        num.insert(begin(num), l - 1);
        num.push_back(u + 1);

        for (int i = 1; i < num.size(); i++) {
            if ((num[i - 1] + 1) <= (num[i] - 1)) res.push_back({(num[i - 1] + 1), (num[i] - 1)});
        }
        return res;
    }
};