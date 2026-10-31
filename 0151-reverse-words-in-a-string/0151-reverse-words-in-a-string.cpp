class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> temp;

        for (int i = 0; i < n; i++) {
            string w = "";
            while (i < n && s[i] == ' ') i++;
            while (i < n && s[i] != ' ') w += s[i++];
            if (w.size()) temp.push_back(w);
        }

        reverse(begin(temp), end(temp));
        s = "";
        for (int i = 0; i < temp.size(); i++) {
            s += temp[i] + ((i == temp.size() - 1) ? "" : " ");
        }
        return s;
    }
};
