class Solution {
public:
    bool vl(string& s) {
        for (auto c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true;
            }
        }
        return false;
    }
    bool doesAliceWin(string s) {
        if (!vl(s)) {
            return false;
        }
        return true;
    }
};