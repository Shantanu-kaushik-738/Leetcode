class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frq(26, 0);
        for (auto& i : word) frq[i - 'a']++;
        sort(rbegin(frq), rend(frq));

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (frq[i] == 0) break;
            cnt += frq[i] * ((i / 8) + 1);
        }
        return cnt;
    }
};