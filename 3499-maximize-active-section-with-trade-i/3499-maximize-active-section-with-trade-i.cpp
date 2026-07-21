class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int cnt1 = 0, sum = 0, prev = -1;

        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                cnt1++;
                i++;
            } else {
                int curr = 0;
                while (i < n && s[i] == '0') {
                    curr++;
                    i++;
                }
                if (prev > 0) {
                    sum = max(sum, (prev + curr));
                }
                prev = curr;
            }
        }
        return cnt1 + sum;
    }
};