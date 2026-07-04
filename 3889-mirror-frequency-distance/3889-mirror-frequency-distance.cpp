class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> f1(10), f2(26);

        for (auto& c : s) {
            if (c <= '9' && c >= '0') f1[c - '0']++;
            else f2[c - 'a']++;
        }

        int res = 0;
        for (int i = 0; i < 5; i++)
            res += abs(f1[i] - f1[9 - i]);

        for (int i = 0; i < 13; i++)
            res += abs(f2[i] - f2[25 - i]);
            
        return res;
    }
};