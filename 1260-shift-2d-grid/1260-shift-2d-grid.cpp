class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        k %= (m * n);

        for (int p = 0; p < k; p++) {
            int curr = grid[0][0];
            int prev = grid[0][0];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    prev = curr;
                    curr = grid[i][j];
                    grid[i][j] = prev;
                }
            }
            grid[0][0] = curr;
        }
        return grid;
    }
};