class Solution {
public:
    vector<int> t;
    bool fnx(int n) {
        if (n == 0) return false;

        if (t[n] != -1) return t[n] == 1;

        for (int i = 1; i <= sqrt(n); i++) {
            if (!fnx(n - (i * i))) return t[n] = 1;
        }
        return t[n] = 0;
    }

    bool winnerSquareGame(int n) {
        t.assign(n + 1, -1);
        return fnx(n);
    }
};