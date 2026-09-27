class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<int> idx;

        for (auto& i : s) {
            if (i == '(') idx.push(res.size());
            else if (i == ')') {
                int l = idx.top();
                idx.pop();
                reverse(begin(res) + l, end(res));
            } else res += i;
        }
        return res;
    }
};
