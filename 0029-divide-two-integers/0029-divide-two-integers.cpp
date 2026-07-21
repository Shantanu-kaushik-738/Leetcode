class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == divisor) return 1;
        int sign = 1;

        if (dividend >= 0 && divisor < 0) sign = -1;
        if (dividend < 0 && divisor >= 0) sign = -1;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) cnt++;
            ans += (1 << cnt);
            n -= (d << cnt);
        }
        ans *= sign;

        if (ans >= INT_MAX) return INT_MAX;
        if (ans <= INT_MIN) return INT_MIN;
        return ans;
    }
};
// (1 << cnt) ->2 ^ (cnt)