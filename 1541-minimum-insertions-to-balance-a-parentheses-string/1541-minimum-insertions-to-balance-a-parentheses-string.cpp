class Solution {
public:
    int minInsertions(string s) {
        int res = 0, cnt = 0; // res -> ( , cnt -> )
        for (auto& i : s) {
            if (i == '(') {
                if (cnt % 2) {
                    res++;
                    cnt--;
                }
                cnt += 2;
            } else {
                cnt--;
                if (cnt < 0) {
                    res++;
                    cnt = 1;
                }
            }
        }
        return res + cnt;
    }
};
