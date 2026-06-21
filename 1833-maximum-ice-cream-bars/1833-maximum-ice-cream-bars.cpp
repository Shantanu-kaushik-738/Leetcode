class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int cnt = 0;
        for (auto& i : costs) {
            if (i <= coins) {
                cnt++;
                coins -= i;
            } else {
                break;
            }
        }
        return cnt;
    }
};