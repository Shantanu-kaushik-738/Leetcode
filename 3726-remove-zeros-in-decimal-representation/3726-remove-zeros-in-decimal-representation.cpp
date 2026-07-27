class Solution {
public:
    long long removeZeros(long long n) {
        long long res = 0;
        long long num = 0;

        while (n) {
            if (n % 10) res = res * 10 + n % 10;
            n /= 10;
        }

        while (res) {
            num = (num * 10) + (res % 10);
            res /= 10;
        }
        return num;
    }
};