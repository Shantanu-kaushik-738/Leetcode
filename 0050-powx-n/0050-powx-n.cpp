class Solution {
public:
    double myPow(double x, int n) {
        long long t = n;
        if (t < 0) {
            x = 1 / x;
            t = -1 * t;
        }

        double res = 1.0;
        while (t > 0) {
            if (t & 1) res *= x; // odd power 
            x *= x;
            t >>= 1; // rigth shift by one bit
        }
        return res;
    }
};
