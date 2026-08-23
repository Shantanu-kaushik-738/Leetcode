class Solution {
public:
    bool sumGame(string s) {
        int l = 0, r = s.length() - 1;
        double s1 = 0;
        while (l < r) {
            // take '?' = mid of (0 - 9); -> 4.5
            if (s[l] == '?') s1 += 4.5;
            if (s[r] == '?') s1 -= 4.5;

            if (s[l] != '?') s1 += s[l] - '0';
            if (s[r] != '?') s1 -= s[r] - '0';
            l++; r--;
        }
        return s1;
    }
};
