class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        s += s;
        int res = 0;

        for (int i = 0; i < n; i++) {
            string temp = s.substr(i, n);
            int p = 0;
            for (int j = 0; j < n - 1; j++) {
                if (temp[j] == temp[j + 1])
                    p++;
            }
            if (p == k) res++;
        }
        return res;
    }
};
