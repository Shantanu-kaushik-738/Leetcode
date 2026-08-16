class Solution {
public:
    int minPenalty(int p, vector<int>& lgs, vector<int>& at) {
        int res = 0;
        int mx = *max_element(begin(lgs), end(lgs));
        for (auto& i : at) {
            int r = i % p;
            if(r < mx) continue;
            res = max(p - r, res);
        }
        return res;
    }
};
