class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int l = 0, r = 0;
        int cnt = 0, mini = 1e9;

        while (r < s.length()) {
            if (s[r] - '0') cnt++;

            while (cnt == k) {
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    res = s.substr(l, r - l + 1);
                } else if (r - l + 1 == mini) {
                    res = min( res, s.substr(l, r - l + 1)); // lexicographically smallest
                }
                if (s[l] - '0') cnt--;
                l++;
            }
            r++;
        }
        return res;
    }
};
