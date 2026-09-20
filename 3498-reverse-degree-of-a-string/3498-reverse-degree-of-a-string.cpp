class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) res += (27 - (s[i] - 'a' + 1)) * (i + 1);
        return res;
    }
};
