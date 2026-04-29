class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.length() < 26) {
            return false;
        }
        vector<bool> alp(26, false);
        int cnt = 0;

        for (auto c : sentence) {
            if (!alp[c - 'a']) {
                alp[c - 'a'] = true;
                cnt++;
            }
        }
        return (cnt == 26);
    }
};