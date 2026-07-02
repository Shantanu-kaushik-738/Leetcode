class Solution {
public:
    void helper(int k, int n, vector<int>& arr, vector<vector<int>>& res, int i) {
        if (n == 0 && k == 0) {
            res.push_back(arr);
            return;
        }

        for (int j = i; j <= 9; j++) {
            if (j > n || k < 1) break;

            arr.push_back(j);
            helper(k - 1, n - j, arr, res, j + 1);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> arr;
        helper(k, n, arr, res, 1);
        return res;
    }
};