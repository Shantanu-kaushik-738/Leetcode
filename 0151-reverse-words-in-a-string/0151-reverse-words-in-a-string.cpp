class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            string w = "";
            while (i < n && s[i] != ' ') {
                w += s[i];
                i++;
            }
            reverse(w.begin(), w.end());

            if ((w.length() > 0) && ans.length() != 0) {
                ans += " " + w;
            } else {
                ans += w;
            }
        }
        return ans;
    }
};