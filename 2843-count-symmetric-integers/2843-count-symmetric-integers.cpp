class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for (int i = low; i <= high; ++i) {
            string s = to_string(i);
            int n = s.length();

            if (n % 2 == 0) {
                int ls = 0;
                int rs = 0;

                for (int j = 0; j < n / 2; ++j) {
                    ls += s[j];
                }

                for (int j = n / 2; j < n; ++j) {
                    rs += s[j];
                }

                if (ls == rs) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};