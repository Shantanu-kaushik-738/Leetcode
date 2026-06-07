class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }
        int maxi = 0;
        int st = 0, end = 0;
        // odd palindrome 
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (maxi < r - l - 1) {
                maxi = r - l - 1;
                st = l + 1;
                end = r - 1;
            }
        }
        // even palindrome 
        for (int i = 0; i < n; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (maxi < r - l - 1) {
                maxi = r - l - 1;
                st = l + 1;
                end = r - 1;
            }
        }
        return s.substr(st, end - st + 1);
    }
};