class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        int d = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') d++;
            else {
                d--;
                if (s[i - 1] == '(') res += 1 << d;
            }
        }
        return res;
    }
};
