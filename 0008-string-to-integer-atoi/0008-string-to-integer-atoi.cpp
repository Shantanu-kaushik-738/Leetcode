class Solution {
private:
    int helper(string s, int i, long long num, int sn) {
        if (i >= s.length() || !isdigit(s[i])) {
            return (int)(sn * num);
        }

        num = num * 10 + (s[i] - '0');

        if (sn * num <= INT_MIN) {
            return INT_MIN;
        }
        if (sn * num >= INT_MAX) {
            return INT_MAX;
        }
        return helper(s, i + 1, num, sn);
    }

public:
    int myAtoi(string s) {
        int i = 0;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        int sn = 1;
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sn *= -1;
            }
            i++;
        }
        return helper(s, i, 0, sn);
    }
};