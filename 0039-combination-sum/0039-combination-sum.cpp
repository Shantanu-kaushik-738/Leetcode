class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& candy, int i, int n, int k, vector<int>& arr) {
        if (i >= n || k < 0) return;
        if (!k) { ans.push_back(arr); return; }

        arr.push_back(candy[i]);
        f(candy, i, n, k - candy[i], arr);
        arr.pop_back();
        f(candy, i + 1, n, k, arr);
    }

    vector<vector<int>> combinationSum(vector<int>& candy, int k) {
        vector<int> arr;
        int i = 0, n = candy.size();
        f(candy, i, n, k, arr);
        return ans;
    }
};
