class Solution {
public:
    int addDigits(int n) {
        if (n <= 9) {
            return n;
        }
        int ans = 0;
        while (n != 0) {
            if (n % 10 != 0) {
                ans += n % 10;
            }
            n /= 10;
        }
        return (ans >= 10) ? addDigits(ans) : ans;
    }
};