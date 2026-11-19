class Solution {
public:
    bool f(vector<vector<char>>& mat, string word, int i, int j, int k, int n, int m) {
        if (k == word.size()) return true;

        if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] != word[k]) return false;

        auto p = mat[i][j];
        mat[i][j] = '.';

        if (f(mat, word, i + 1, j, k + 1, n, m)) return true;
        if (f(mat, word, i, j - 1, k + 1, n, m)) return true;
        if (f(mat, word, i, j + 1, k + 1, n, m)) return true;
        if (f(mat, word, i - 1, j, k + 1, n, m)) return true;

        mat[i][j] = p;
        return false;
    }

    bool exist(vector<vector<char>>& mat, string word) {
        int i = 0, j = 0, k = 0, n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (f(mat, word, i, j, k, n, m)) return true;
        return false;
    }
};