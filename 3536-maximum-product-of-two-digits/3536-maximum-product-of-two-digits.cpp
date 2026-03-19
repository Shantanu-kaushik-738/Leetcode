class Solution {
public:
    int maxProduct(int n) {
        int st = 0;
        int lst = 0;

        while (n != 0) {
            int d = n % 10;

            if (d > st) {
                lst = st;
                st = d;
            } else if (lst < d) {
                lst = d;
            }
            n /= 10;
        }
        return (st * lst);
    }
};