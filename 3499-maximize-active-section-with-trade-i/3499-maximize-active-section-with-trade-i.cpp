class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt1 = count(begin(s), end(s), '1');
        int n = s.length();
        vector<int> zero;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int st = i;
                while (i < n && s[i] == '0') i++;
                zero.push_back(i - st);
            } else i++;
        }

        int ms = 0;
        for (int j = 1; j < zero.size(); j++) {
            ms = max(ms, (zero[j] + zero[j - 1]));
        }
        return ms + cnt1;
    }
};