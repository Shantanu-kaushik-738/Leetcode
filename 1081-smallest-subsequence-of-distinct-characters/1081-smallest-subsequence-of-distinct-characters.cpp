class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> li(26, -1);
        vector<bool> un(26, false);
        vector<char> st;

        for (int i = 0; i < s.length(); i++) {
            li[s[i] - 'a'] = i;
        }

        int j = 0;
        for (auto& i : s) {
            if (un[i - 'a']) {
                j++;
                continue;
            } else {
                while (!st.empty() && st.back() > i && li[st.back() - 'a'] > j) {
                    un[st.back() - 'a'] = false;
                    st.pop_back();
                }
                st.push_back(i);
                un[i - 'a'] = true;
            }
            j++;
        }

        string res = "";
        for (auto& i : st) res += i;
        return res;
    }
};
