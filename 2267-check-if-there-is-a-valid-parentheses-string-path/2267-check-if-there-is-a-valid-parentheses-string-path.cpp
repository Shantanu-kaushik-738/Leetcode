class Solution {
public:
    int n, m;
    int t[101][101][201];

    bool funx(int i, int j, int open, vector<vector<char>>& grid) {
        open += (grid[i][j] == '(') ? 1 : -1;

        if (open < 0) return false;

        if (i == n - 1 && j == m - 1) return t[i][j][open] = !open;

        if (t[i][j][open] != -1) return t[i][j][open];

        if (i + 1 < n) if (funx(i + 1, j, open, grid)) return t[i][j][open] = true; // down
        if (j + 1 < m) if (funx(i, j + 1, open, grid)) return t[i][j][open] = true; // right
        return t[i][j][open] = false;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if ((n + m - 1) % 2) return false; // total length of path
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') return false;

        memset(t, -1, sizeof(t));

        return funx(0, 0, 0, grid); 
    }
};
