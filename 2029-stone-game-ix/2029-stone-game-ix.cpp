class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> sum(3);
        for (auto& i : stones) sum[i % 3]++;

        if (sum[1] == 0 && sum[2] == 0) return false;
        if (sum[0] % 2 == 0) return sum[1] && sum[2];

        return abs(sum[1] - sum[2]) > 2;
    }
};
