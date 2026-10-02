class Solution {
public:
    vector<string> res;
    
    void gP(string curr, int& n, int op, int cl) {
        if (op == n && cl == n) {
            res.push_back(curr);
            return;
        }

        if (op < n) {
            curr.push_back('(');
            gP(curr, n, op + 1, cl);
            curr.pop_back();
        }

        if (cl < op) {
            curr.push_back(')');
            gP(curr, n, op, cl + 1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int op = 0, cl = 0;
        gP("", n, op, cl);
        return res;
    }
};
