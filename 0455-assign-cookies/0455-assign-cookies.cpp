class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int l = 0, r = 0; // l - child , r = cookie
        while (l < g.size() && r < s.size()) {
            if (g[l] <= s[r]) l++;
            r++;
        }
        return l;
    }
};
