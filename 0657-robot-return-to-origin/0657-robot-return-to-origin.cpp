class Solution {
public:
    bool judgeCircle(string moves) {
        int r = 0;
        int u = 0;

        for (char v : moves) {
            if (v == 'R') {
                r++;
            } else if (v == 'L') {
                r--;
            } else if (v == 'U') {
                u++;
            } else if (v == 'D') {
                u--;
            }
        }
        return (r == 0 && u == 0) ? true : false;
    }
};