class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        sort(begin(inter), end(inter), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int cnt = 0, p = 0;

        for (auto& i : inter) {
            if (i[1] > p) {
                cnt++;
                p = i[1];
            }
        }
        return cnt;
    }
};