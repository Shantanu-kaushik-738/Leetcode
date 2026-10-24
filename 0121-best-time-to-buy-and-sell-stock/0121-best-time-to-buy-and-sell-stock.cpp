class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], p = 0;
        for (auto& i : prices) {
            p = max(p, i - mini);
            mini = min(mini, i);
        }
        return p;
    }
};
