vector<int> ncr(int r) {
    int res = 1;
    vector<int>ans;
    ans.push_back(res);
    for (int i = 1; i < r; i++) {
        res *= (r - i);
        res /= (i );
        ans.push_back(res);
    }
    return ans;
}

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int r = 1; r <= n; r++) {
            ans.push_back(ncr(r));
        }
        return ans;
    }
};