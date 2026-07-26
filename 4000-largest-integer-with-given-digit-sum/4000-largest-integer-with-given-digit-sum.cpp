class Solution {
public:
    int largestInteger(int n, int s) {
        int res = 0;

        for (int i = 0; i < n; i++) {
            int d = min(9, s);
            res = res * 10 + d;
            s -= d;
        }
        return s == 0 ? res : -1;
    }
};