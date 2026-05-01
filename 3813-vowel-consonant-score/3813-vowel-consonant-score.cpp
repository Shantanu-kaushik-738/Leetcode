class Solution {
public:
    int vowelConsonantScore(string s) {
        int se = 0;
        int so = 0;

        for (auto c : s) {
            if (c >= 'a' && c <= 'z') {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    se++;
                } else {
                    so++;
                }
            }
        }
        if (so == 0) {
            return 0;
        }
        return floor(se / so);
    }
};