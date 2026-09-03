class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = n, i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                res += peak;
                i++;
            }

            int down = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                down++;
                res += down;
                i++;
            }
            res -= min(peak, down);
        }
        return res;
    }
};
