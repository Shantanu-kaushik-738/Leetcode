class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> v(256, -1);

        int l = 0, r = 0;
        int ml = 0;

        while (r < n) {
            if (v[s[r]] != -1) {
                if (v[s[r]] >= l) {
                    l = v[s[r]] + 1;
                }
            }
            ml = max(ml, (r - l + 1));
            v[s[r]] = r;
            r++;
        }
        return ml;
    }
};