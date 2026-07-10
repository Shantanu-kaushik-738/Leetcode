class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool find(int i, int j, int idx, vector<vector<char>>& board, string word) {
        if (idx == word.length()) return true;

        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || board[i][j] == '.' || board[i][j] != word[idx]) return false;

        char c = board[i][j];
        board[i][j] = '.'; // visited

        for (auto& d : dir) { // for each 4 direction
            if (find(i + d[0], j + d[1], idx + 1, board, word)) return true;
        }

        board[i][j] = c; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && find(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};