class Solution {
public:
    bool f(int l, int r, string& s) {
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    }

    int maxPalindromes(string& s, int k) {
        int n = s.size();
        int cnt = 0, left = 0;

        for (int r = k - 1; r < n; r++) {
            int l = r - k + 1;
            if (l >= left && f(l, r, s)) {
                cnt++;
                left = r + 1;
            } else if (l > left && f(l - 1, r, s)) {
                cnt++;
                left = r + 1;
            }
        }
        return cnt;
    }
};
