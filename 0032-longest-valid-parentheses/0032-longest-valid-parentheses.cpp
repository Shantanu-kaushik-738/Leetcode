class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int op = 0, cl = 0;
        for (auto& i : s) {
            if (i == '(') op++;
            else cl++;
            if (op == cl) res = max(res, 2 * op);
            else if (cl > op) op = cl = 0;
        }

        op = cl = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') op++;
            else cl++;
            if (op == cl) res = max(res, 2 * op);
            else if (cl < op) op = cl = 0;
        }
        return res;
    }
};
