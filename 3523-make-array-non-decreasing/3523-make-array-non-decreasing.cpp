class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int cnt = 0;
        int pr = 0;

        for (auto& i : nums) {
            if (pr <= i) {
                pr = i;
                cnt++;
            }
        }
        return cnt;
    }
};