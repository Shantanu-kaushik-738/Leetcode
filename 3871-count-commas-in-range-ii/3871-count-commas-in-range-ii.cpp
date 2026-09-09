class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        long long i = 1e3;
        while (i <= n) {
            res += (n - i + 1);
            i *= 1e3;
        }
        return res;
    }
};
