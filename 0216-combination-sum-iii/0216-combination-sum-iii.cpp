class Solution {
public:
    void helper(int k, int n, vector<int>& arr, vector<vector<int>>& res, int i) {
        if (n == 0 && k == 0) {
            res.push_back(arr);
            return;
        }

        if (i > 9 || n < 0 || k < 1) return;

        arr.push_back(i); // inclusion
        helper(k - 1, n - i, arr, res, i + 1);
        arr.pop_back(); // exclusion
        helper(k, n, arr, res, i + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> arr;
        helper(k, n, arr, res, 1);
        return res;
    }
};