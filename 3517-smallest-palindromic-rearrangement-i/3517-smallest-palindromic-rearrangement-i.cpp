class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> frq;
        for (auto& i : s) frq[i]++;

        string ans = "";
        string md = "";

        for (char i = 'a'; i <= 'z'; i++) {
            if (frq[i] % 2 == 1) {
                md += i;
            }
            ans.append(frq[i] / 2, i);
        }

        string res = ans;
        res += md;
        reverse(begin(ans), end(ans));
        res += ans;

        return res;
    }
};
