class Solution {
public:
    int t[501][501];
    int funx(int l, int r, vector<int>& sum) {
        if (l >= r) return 0;

        if (t[l][r] != -1) return t[l][r];

        int res = 0;
        for (int i = l; i < r; i++) { // find the mid point for division
            int ls = sum[i] - (l > 0 ? sum[l - 1] : 0); // sum of left part
            int rs = sum[r] - sum[i]; // sum of the right part

            if (ls < rs) res = max(res, ls + funx(l, i, sum)); // remove the right part
            else if (ls > rs) res = max(res, rs + funx(i + 1, r, sum)); // remove the left part
            else res = max({res, ls + funx(l, i, sum), rs + funx(i + 1, r, sum)}); // ls == rs -> check the best score from both side 
        }
        return t[l][r] = res;
    }

    int stoneGameV(vector<int>& stv) {
        int n = stv.size();

        vector<int> sum(n, 0); // prefix sum
        sum[0] = stv[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + stv[i];

        memset(t, -1, sizeof(t));
        return funx(0, n - 1, sum);
    }
};
