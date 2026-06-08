class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ml = 0;

        for (int i = 0; i < n; i++) {
            vector<int> v(256);
            int l = 0;
            for (int j = i; j < n; j++) {
                if (v[s[j]] == 1) {
                    break;
                }
                l = j - i + 1;
                ml = max(ml, l);
                v[s[j]] = 1;
            }
        }
        return ml;
    }
};