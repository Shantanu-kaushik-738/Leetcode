class Solution {
public:
    int minDays(int n) {
        vector<int> p(n + 1, 1e9);
        p[0] = 0; // starting day

        for (int i = 1; i <= n; i++) { // streak
            int point = 0; // curr point
            for (int j = 1; ; j++) {
                point += j; // triangular number

                if (point > i) break; // target point reach
                if (point == i) p[i] = min(p[i], j); // without skip j days
                else p[i] = min(p[i], p[i - point] + 1 + j); // remaining scr + skip(1) + days(j)
            }
        }
        return p[n];
    }
};