class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ') {
            i++;
        }

        int sn = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sn = -1;
            }
            i++;
        }

        long long num = 0;
        while (i < n && isdigit(s[i])) {
            int d = s[i] - '0';
            num = num * 10 + d;

            if (sn * num > INT_MAX) {
                return INT_MAX;
            }
            if (sn * num < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return (sn * num);
    }
};