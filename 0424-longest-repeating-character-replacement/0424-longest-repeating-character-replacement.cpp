class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0, r = 0, frq = 0;
        vector<int> mp(26);

        while (r < s.length()) {
            mp[s[r] - 'A']++;
            frq = max(frq, mp[s[r] - 'A']);
            if (r - l + 1 - frq > k) mp[s[l++] - 'A']--;
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
