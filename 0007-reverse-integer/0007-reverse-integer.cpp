class Solution {
public:
    int reverse(int n) {
        long long r = 0;

        while (n) {
            int d = n % 10;
            r = r * 10 + d;
            n /= 10;

            if (r > INT_MAX || r < INT_MIN) {
                return 0;
            }
        }
        return (int)r;
    }
};