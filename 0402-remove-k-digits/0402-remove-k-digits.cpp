class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        for (int i = 0; i < num.size(); i++) {
            while (!s.empty() && k && ((s.top() - '0') > (num[i] - '0'))) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while (k) {
            s.pop();
            k--;
        }

        if (s.empty()) return "0";

        string res = "";
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }

        while (res.size() && res.back() == '0') res.pop_back();
        reverse(begin(res), end(res));
        return res.size() ? res : "0";
    }
};
