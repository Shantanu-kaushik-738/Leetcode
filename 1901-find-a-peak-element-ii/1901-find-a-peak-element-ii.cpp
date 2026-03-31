class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool ip = true;

                if (i > 0 && mat[i][j] <= mat[i - 1][j]) {
                    ip = false;
                }
                if (i < n - 1 && mat[i][j] <= mat[i + 1][j]) {
                    ip = false;
                }
                if (j > 0 && mat[i][j] <= mat[i][j - 1]) {
                    ip = false;
                }
                if (j < m - 1 && mat[i][j] <= mat[i][j + 1]) {
                    ip = false;
                }

                if (ip) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};