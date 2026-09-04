class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newi) {
        vector<vector<int>> res;
        int i = 0;
        int n = inter.size();

        while (i < n && inter[i][1] < newi[0]) res.push_back(inter[i++]);

        while (i < n && inter[i][0] <= newi[1]) {
            newi[0] = min(newi[0], inter[i][0]);
            newi[1] = max(newi[1], inter[i][1]);
            i++;
        }
        res.push_back(newi);
        while (i < n) res.push_back(inter[i++]);

        return res;
    }
};
