class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int cnt = 0;
        for (auto c : sentences) {
            int ci = 0;
            for (auto ch : c) {
                if (ch == ' ') {
                    ci++;
                }
            }
            cnt = max(cnt, ci);
        }
        return cnt + 1;
    }
};