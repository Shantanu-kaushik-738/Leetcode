class Solution {
public:
    int countPrimes(int n) {
        vector<bool> ip(n + 1, true);
        int cn = 0;

        for (int i = 2; i < n; i++) {
            if (ip[i]) {
                cn++;

                for (int j = i * 2; j < n; j += i) {
                    ip[j] = false;
                }
            }
        }
        return cn;
    }
};