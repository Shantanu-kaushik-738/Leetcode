class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i <= n + 10; i++) {
            int p = 1;
            int j = i;
            while (j) {
                p *= j % 10;
                j /= 10;
            }
            if (p % t == 0) return i;
        }
        return -1;
    }
};