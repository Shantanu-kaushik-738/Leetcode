class Solution {
public:
    int reverse(int n) {
        int reverse = 0;

        while (n) {
            int d = n % 10;
            if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10) {
                return 0;
            }
            reverse = reverse * 10 + d;
            n /= 10;
        }
        return reverse;
    }
};