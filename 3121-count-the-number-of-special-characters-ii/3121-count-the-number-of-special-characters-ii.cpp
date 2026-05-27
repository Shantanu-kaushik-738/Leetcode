class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26, -1);
        vector<int> upp(26, -1);

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];

            if (islower(ch)) {
                low[ch - 'a'] = i;
            } else if (upp[ch - 'A'] == -1) {
                upp[ch - 'A'] = i;
            }
        }
        int cnt = 0;

        for (int i = 0; i < 26; i++) {
            if (low[i] != -1 && upp[i] != -1 && upp[i] > low[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};