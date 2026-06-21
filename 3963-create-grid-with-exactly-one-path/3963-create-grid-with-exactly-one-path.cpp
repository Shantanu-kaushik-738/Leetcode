class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string> ans(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0 || i == n - 1) {
                    ans[i].push_back('.');
                } else {
                    ans[i].push_back('#');
                }
            }
        }
        return ans;
    }
};