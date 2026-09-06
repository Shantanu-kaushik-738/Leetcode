class Solution {
public:
    int dp[1001][1001];
    int funx(string& s, string& t, int i, int j) {
        if (j == t.length()) return dp[i][j] = 1;
        if (i == s.length()) return dp[i][j] = 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] != t[j]) return dp[i][j] = funx(s, t, i + 1, j);
        return dp[i][j] = funx(s, t, i + 1, j + 1) + funx(s, t, i + 1, j);
    }
    
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return funx(s, t, 0, 0);
    }
};
