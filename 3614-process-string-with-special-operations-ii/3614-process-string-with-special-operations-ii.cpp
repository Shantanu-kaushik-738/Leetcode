class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long l = 0;

        for (auto& c : s) { // for l
            if (c == '*') {
                if (l > 0)
                    l--;
            } else if (c == '#') {
                l *= 2;
            } else if (c == '%') {
                continue;
            } else { // char 'a' - 'z'
                l++;
            }
        }

        if (k >= l) {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--) { // for k & l
            if (s[i] == '*') {
                l++;
            } else if (s[i] == '%') {
                k = l - k - 1;
            } else if (s[i] == '#') {
                l /= 2;
                k %= l;
            } else { // char 'a' - 'z'
                l--;
            }
            if (k == l) {
                return s[i];
            }
        }
        return '.';
    }
};