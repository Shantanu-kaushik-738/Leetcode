class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int p = 0;
        int pi = 0;

        for (auto i : moves) {
            if (i == 'L') {
                p++;
            }
            if (i == 'R') {
                p--;
            }
            if (i == '_') {
                pi++;
            }
        }
        return abs(p) + pi;
    }
};