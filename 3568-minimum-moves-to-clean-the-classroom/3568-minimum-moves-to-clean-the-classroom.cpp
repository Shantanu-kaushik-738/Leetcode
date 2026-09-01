class Solution {
public:
    int minMoves(vector<string>& cr, int en) {
        int m = cr.size();
        int n = cr[0].size();
        vector<vector<int>> ltr(m, vector<int>(n, -1));
        int x = -1, y = -1;
        int lcnt = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (cr[i][j] == 'S') {
                    x = i;
                    y = j;
                } else if (cr[i][j] == 'L')
                    ltr[i][j] = lcnt++;
            }
        }
        if (lcnt == 0)
            return 0;

        int all = (1 << lcnt) - 1;
        queue<tuple<int, int, int, int, int>> q;
        q.push({x, y, en, 0, 0});

        vector<vector<vector<vector<bool>>>> visit(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(en + 1,
                                           vector<bool>(1 << lcnt, false))));
        visit[x][y][en][0] = true;

        int dir[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c, e, mk, st] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    cr[nr][nc] != 'X') {
                    int nxt = e - 1;
                    int nxtm = mk;

                    if (cr[nr][nc] == 'L') {
                        nxtm |= (1 << ltr[nr][nc]);
                    }

                    if (nxtm == all) {
                        return st + 1;
                    }

                    if (cr[nr][nc] == 'R') {
                        nxt = en;
                    }

                    if (nxt == 0 && cr[nr][nc] != 'R') continue;

                    if (!visit[nr][nc][nxt][nxtm]) {
                        visit[nr][nc][nxt][nxtm] = true;
                        q.push({nr, nc, nxt, nxtm, st + 1});
                    }
                }
            }
        }
        return -1;
    }
};
