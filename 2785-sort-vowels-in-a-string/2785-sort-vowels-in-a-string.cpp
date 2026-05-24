class Solution {
private:
    bool vl(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        return false;
    }

public:
    string sortVowels(string s) {

        vector<char> v;
        for (auto& c : s) {
            if (vl(c)) {
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());

        int i = 0;
        for (auto& c : s) {
            if (vl(c)) {
                c = v[i];
                i++;
            }
        }
        return s;
    }
};