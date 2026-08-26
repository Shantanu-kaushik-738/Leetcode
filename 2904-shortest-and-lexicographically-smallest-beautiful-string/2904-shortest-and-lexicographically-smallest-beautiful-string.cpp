class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int mini = 1e9;

        for (int i = 0; i < s.length(); i++) {
            int cnt = 0;
            for (int j = i; j < s.length(); j++) {
                if (s[j] - '0') cnt++;
                if (cnt == k) {
                    if (j - i + 1 < mini) {
                        mini = j - i + 1;
                        res = s.substr(i, j - i + 1);
                    } else if (j - i + 1 == mini) {
                        res = min(res, s.substr(i, j - i + 1)); // lexicographically smallest
                    }
                    break;
                }
            }
        }
        return res;
    }
};