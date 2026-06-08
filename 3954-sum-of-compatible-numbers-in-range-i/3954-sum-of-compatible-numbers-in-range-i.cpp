class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int s = 0;
        for (int i = max(1, n - k); i <= n + k; i++) {
            if (abs(n - i) <= k && (n & i) == 0) {
                s += i;
            }
        }
        return s;
    }
};