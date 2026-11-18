class Solution {
public:
    vector<string> ans;
    void f(string s, int n, int op, int cl) {
        if (s.size() == 2 * n) { ans.push_back(s); return; }

        if (op < n) {
            s += "(";
            f(s, n, op + 1, cl);
            s.pop_back();
        }
        if (cl < op) {
            s += ")";
            f(s, n, op, cl + 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int op = 0, cl = 0;
        f("", n, op, cl);
        return ans;    
    }
};
