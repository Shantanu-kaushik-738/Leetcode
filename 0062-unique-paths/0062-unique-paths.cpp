class Solution {
private:
    int solve(int i, int j, int n, int m, vector<vector<int>>& t) {
        if (i == n - 1 && j == m - 1) {
            return 1;
        }
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        return t[i][j] = (solve(i, j + 1, n, m, t) + solve(i + 1, j, n, m, t));
    }

public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, n, m, t);
    }
};