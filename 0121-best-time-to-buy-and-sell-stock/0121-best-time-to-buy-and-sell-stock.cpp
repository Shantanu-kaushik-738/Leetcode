class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int pr = 0;

        for (auto& i : prices) {
            int cs = i - mini;
            pr = max(pr, cs);
            mini = min(mini, i);
        }
        return pr;
    }
};