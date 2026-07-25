class Solution {
public:
    int maxProduct(int n) {
        int low = 0, high = 0;

        while (n) {
            if (n % 10 > high) {
                low = high;
                high = n % 10;
            } else if (n % 10 > low) low = n % 10;
            n /= 10;
        }
        return low * high;
    }
};