class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        int l = 0, r = 0;
        vector<int> frq(26, 0);

        while (r < s.length()) {
            frq[s[r] - 'a']++;
            while (frq[s[r] - 'a'] > 2) {
                frq[s[l] - 'a']--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
