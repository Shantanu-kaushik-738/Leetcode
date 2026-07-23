class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long t = n;

        if (x == 1.0) return 1.0;
        if (t < 0) t = -1 * t;

        while (t > 0) {
            if (t % 2 == 1) {
                ans *= x;
                t--;
            } else {
                x *= x;
                t /= 2;
            }
        }
        return (n < 0) ? 1.0 / ans : ans;
    }
};