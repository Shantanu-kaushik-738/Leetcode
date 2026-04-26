class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int un = 0;

        for (int x : fruits) {
            bool pl = false;
            for (int i = 0; i < n; i++) {
                if (baskets[i] >= x) {
                    baskets[i] = 0;
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