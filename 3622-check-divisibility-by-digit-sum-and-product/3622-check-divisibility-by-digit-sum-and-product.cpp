class Solution {
public:
    bool checkDivisibility(int n) {
        int o = n;
        int s = 0;
        int p = 1;

        while (n != 0) {
            s += n % 10;
            p *= n % 10;
            n /= 10;
        }
        return (o % (s + p) == 0);
    }
};