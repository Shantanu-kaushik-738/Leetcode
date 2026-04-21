class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sm = 0;

        for (int i = 0; i < n; i++) {
            sm += mat[i][i];
            if (i != n - i - 1) {
                sm += mat[i][n - i - 1];
            }
        }

        return sm;
    }
};