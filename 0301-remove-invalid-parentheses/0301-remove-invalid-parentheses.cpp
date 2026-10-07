class Solution {
public:
    set<string> st;
    int n, len = 0;
    string curr = "";

    void funx(string& s, int i, int cnt) {
        if (cnt < 0) return;

        if (i == n) {
            if (!cnt) {
                if (curr.size() > len) {
                    len = curr.size();
                    st.clear();
                }
                if (curr.size() == len) st.insert(curr);
            }
            return;
        }

        if (s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            funx(s, i + 1, cnt);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        funx(s, i + 1, cnt + (s[i] == '(' ? 1 : -1));
    
        curr.pop_back();;
        funx(s, i + 1, cnt);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        funx(s, 0, 0);
        return vector<string> (begin(st), end(st));
    }
};
