class Solution {
public:
    string processStr(string s) {
        string res = "";

        for (auto& c : s) {
            if ((!res.empty()) && c == '*') {
                res.pop_back();
            } else if ((!res.empty()) && c == '#') {
                res.append(res);
            } else if ((!res.empty()) && c == '%') {
                reverse(begin(res), end(res));
            } else if (c >= 'a' && c <= 'z') {
                res.push_back(c);
            }
        }
        return res;
    }
};