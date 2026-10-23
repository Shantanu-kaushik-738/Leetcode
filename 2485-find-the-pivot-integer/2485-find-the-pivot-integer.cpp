class Solution {
public:
    int pivotInteger(int n) {
        int rs = n * (n + 1) / 2;
        int ls = 0;

        for (int i = 1; i <= n; i++) {
            ls += i;
            if (ls == rs) return i;
            rs -= (i);
        }
        return -1;
    }
};
