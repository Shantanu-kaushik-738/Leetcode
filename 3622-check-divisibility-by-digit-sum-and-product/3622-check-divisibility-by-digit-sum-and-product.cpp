class Solution {
public:
    bool checkDivisibility(int n) {
        int o = n, s = 0, p = 1;
        while (n) {
            s += n % 10;
            p *= n % 10;
            n /= 10;
        }
        return o % (s + p) == 0;
    }
};
