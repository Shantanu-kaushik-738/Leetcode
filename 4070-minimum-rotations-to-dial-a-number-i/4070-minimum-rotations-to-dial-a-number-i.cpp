class Solution {
public:
    int minRotations(string s) {
        int cnt = 0;
        int pre = 0;

        for (int i = 0; i < 10; i++) {
            int curr = s[i] - '0';
            cnt += min(abs(curr - pre), 10 - abs(pre - curr));
            pre = curr;
        }
        return cnt;
    }
};
