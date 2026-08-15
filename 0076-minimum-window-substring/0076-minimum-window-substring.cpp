class Solution {
public:
    string minWindow(string s, string t) {
        int len = 1e9, idx = -1;
        int l = 0, r = 0, cnt = 0;

        vector<int> frq(256, 0);
        for (auto& i : t) frq[i]++;

        while (r < s.length()) {
            if (frq[s[r]] > 0) cnt++;
            frq[s[r]]--;

            while (cnt == t.length()) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    idx = l;
                }
                frq[s[l]]++;
                if (frq[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return idx == -1 ? "" : s.substr(idx, len);
    }
};
