class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& oi, int fs, int fe) {
        sort(begin(oi), end(oi));
        vector<vector<int>> mrg;

        for (auto& i : oi) {
            if (mrg.empty() || mrg.back()[1] < i[0] - 1) {
                mrg.push_back(i);
            } else {
                mrg.back()[1] = max(mrg.back()[1], i[1]);
            }
        }

        vector<vector<int>> ans;
        for (auto& i : mrg) {
            if (i[1] < fs) {
                ans.push_back(i);
            } else if (i[0] > fe) {
                ans.push_back(i);
            } else {
                if (i[0] < fs) {
                    ans.push_back({i[0], fs - 1});
                }
                if (i[1] > fe) {
                    ans.push_back({fe + 1, i[1]});
                }
            }
        }
        return ans;
    }
};