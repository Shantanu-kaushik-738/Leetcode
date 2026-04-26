class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int un = 0;
        vector<bool> us(n, false);

        for (int x : fruits) {
            bool pl = false;
            for (int i = 0; i < n; i++) {
                if (!(us[i]) && baskets[i] >= x) {
                    us[i] = true;
                    pl = true;
                    break;
                }
            }
            if (!pl) {
                un++;
            }
        }
        return un;
    }
};