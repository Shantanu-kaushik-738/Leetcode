class Solution {
public:
    vector<string> res;
    bool valid(string str) {
        int cnt = 0;

        for (auto& c : str) {
            if (c == '(') {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt < 0) {
                return false;
            }
        }
        return cnt == 0;
    }

    void solve(string curr, int& n) {
        if (curr.size() == 2 * n) {
            if (valid(curr)) {
                res.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        solve("", n);
        return res;
    }
};