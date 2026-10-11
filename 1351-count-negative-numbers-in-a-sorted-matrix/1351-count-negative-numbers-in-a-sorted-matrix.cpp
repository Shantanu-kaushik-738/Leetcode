class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size() - 1, m = grid[0].size(), col = 0;
        int cnt = 0;

        while (row >= 0 && col < m) {
            if (grid[row][col] >= 0) col++;
            else {
                cnt += (m - col);
                row--;
            }
        }
        return cnt;
    }
};
