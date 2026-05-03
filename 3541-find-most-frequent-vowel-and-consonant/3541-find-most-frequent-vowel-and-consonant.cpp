class Solution {
public:
    int maxFreqSum(string s) {
        int c1 = 0;
        int c2 = 0;
        unordered_map<char, int> mp;

        for (auto c : s) {
            mp[c]++;
        }

        int sv = 0;
        int sc = 0;

        for (auto p : mp) {
            char c = p.first;
            int f = p.second;

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                sv = max(sv, f);
            } else {
                sc = max(sc, f);
            }
        }
        return (sv + sc);
    }
};