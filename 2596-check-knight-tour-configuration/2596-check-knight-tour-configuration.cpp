class Solution {
public:
    bool helper(vector<vector<int>>& grid, int r, int c, int n, int k) {

        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != k) return false;

        if (k == (n * n) - 1) return true;

        // all the 8 moves of knight
        bool m1 = helper(grid, r - 2, c + 1, n, k + 1);
        bool m2 = helper(grid, r - 1, c + 2, n, k + 1);
        bool m3 = helper(grid, r + 1, c + 2, n, k + 1);
        bool m4 = helper(grid, r + 2, c + 1, n, k + 1);
        bool m5 = helper(grid, r + 2, c - 1, n, k + 1);
        bool m6 = helper(grid, r + 1, c - 2, n, k + 1);
        bool m7 = helper(grid, r - 1, c - 2, n, k + 1);
        bool m8 = helper(grid, r - 2, c - 1, n, k + 1);

        return m1 || m2 || m3 || m4 || m5 || m6 || m7 || m8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size(), 0);
    }
};