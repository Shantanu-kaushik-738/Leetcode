class Solution {
public:
    int scoreOfString(string s) {
        int sm = 0;
        
        for (int i = 0; i < s.length() - 1; i++) {
            sm += abs(s[i] - s[i + 1]);
        }
        return sm;
    }
};