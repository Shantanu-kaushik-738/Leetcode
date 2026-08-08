class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int cnt = 0;
        int n = strs[0].length();
        int m = strs.size() - 1;

        for (int i = 0; i < n; i++) {
            if (strs[0][i] == strs[m][i]) {
                cnt++;
            } else {
                break;
            }
        }
        return ((cnt == 0) ? "" : strs[0].substr(0, cnt));
    }
};