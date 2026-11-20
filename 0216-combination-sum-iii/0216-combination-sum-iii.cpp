class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& nums, int k, int n, int i) {
        if (!n && !k) { ans.push_back(nums); return; }
        if (i < 1 || i > 9 || n < 1) return;
        nums.push_back(i);
        f(nums, k - 1, n - i, i + 1);
        nums.pop_back();
        f(nums, k, n, i + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        f(nums, k, n, 1);
        return ans;    
    }
};
