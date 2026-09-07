class Solution {
public:
    int m = 1e9 + 7;
    int dp[2001];
    vector<int> prev; 

    int funx(int n) {
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        
        int t = (2 * funx(n - 1)) % m;

        if(prev[n]) {
            t = (t - funx(prev[n] - 1) + m) % m;
        }
        return dp[n] = t;
    }

    int distinctSubseqII(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);

        vector<int> last(26, 0);
        for(int i = 1; i <= n; i++) {
            prev[i] = last[s[i-1] -'a'];
            last[s[i-1] -'a'] = i;
        }
        return (funx(n) - 1 + m) % m;
    }
};