class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> res, ans;
        for (auto& i : nums) {
            if (res.empty() || (!ans.empty() && res.back() > ans.back())) res.push_back(i);
            else ans.push_back(i);
        }
        for (auto& i : ans) res.push_back(i);
        return res;
    }
};
