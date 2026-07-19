class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char, int> frq;
        for (auto& i : s) frq[i]++;

        string res = "";
        for (int i = 0; i < frq[y]; i++) res.push_back(y);

        for (auto& i : frq) {
            char c = i.first;
            if (c != x && c != y) {
                for (int j = 0; j < i.second; j++) res.push_back(c);
            }
        }
        for (int i = 0; i < frq[x]; i++) res.push_back(x);
        return res;
    }
};