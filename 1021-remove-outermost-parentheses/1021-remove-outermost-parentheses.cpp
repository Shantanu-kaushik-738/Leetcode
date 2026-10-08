class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int d = 0;
        for (auto& i : s) {
            if (i == '(') {
                if (d) res += i;
                d++;
            } else {
                d--;              
                if (d) res += i;
            }
        }
        return res;
    }
};
