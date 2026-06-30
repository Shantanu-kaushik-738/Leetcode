class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        vector<int> temp(3, 0);

        int i = 0, j = 0;
        while (j < n) {
            auto c = s[j];
            temp[c - 'a']++;

            while (temp[0] > 0 && temp[1] > 0 && temp[2] > 0) {
                cnt += (n - j);
                temp[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};