class Solution {
public:
    int distinctSubseqII(string s) {
        int m = 1e9 + 7;
        vector<long long> last(26); // cnt the number of subseq of char

        for (auto& i : s) {
            long long t = 0;
            for (int j = 0; j < 26; j++)
                t = (t + last[j]) % m;

            last[i - 'a'] = (t + 1) % m;
        }

        long long ans = 0;
        for (int i = 0; i < 26; i++)
            ans = (ans + last[i]) % m;
        return (int)ans;
    }
};
