class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int n, int m) {

        if (n * m != original.size()) {
            return {};
        }

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < original.size(); i++) {
            ans[i / m][i % m] = original[i];
        }
        return ans;
    }
};