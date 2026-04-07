class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = 0;
        for (char ch : columnTitle) {
            n = n * 26 + (ch - 64);
        }
        return n;
    }
};