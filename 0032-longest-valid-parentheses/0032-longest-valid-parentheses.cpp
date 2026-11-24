class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt = 0, op = 0, cl = 0;

        for (int i = 0; i < ssize(s); i++) {
            if (s[i] == '(') op++;
            else cl++;
            if (op == cl) cnt = max(cnt, 2 * op);
            else if (cl > op) op = cl = 0;
        }

        op = 0, cl = 0;
        for (int i = ssize(s) - 1; i >= 0; i--) {
            if (s[i] == '(') op++;
            else cl++;
            if (op == cl) cnt = max(cnt, 2 * op);
            else if (op > cl) op = cl = 0;
        }
        return cnt;
    }
};
