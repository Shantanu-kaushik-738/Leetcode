class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        stack<char> st;

        for (auto& i : s) {
            if (i == '(') {
                st.push(res);
                res = 0;
            } else {
                res = st.top() + max(res * 2, 1);
                st.pop();
            }
        }
        return res;
    }
};
