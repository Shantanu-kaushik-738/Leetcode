class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int cnt = 0;
        for (int i = 0; i < sentences.size(); i++) {
            int ci = 0;
            for (auto ch : sentences[i]) {
                if (ch == ' ') {
                    ci++;
                }
            }
            cnt = max(cnt, ci);
        }
        return cnt + 1;
    }
};