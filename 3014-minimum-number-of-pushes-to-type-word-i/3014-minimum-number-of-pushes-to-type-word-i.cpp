class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (i <= 8) cnt++;
            else if (i <= 16) cnt += 2;
            else if (i <= 24) cnt += 3;
            else cnt += 4;
        }
        return cnt;
    }
};
