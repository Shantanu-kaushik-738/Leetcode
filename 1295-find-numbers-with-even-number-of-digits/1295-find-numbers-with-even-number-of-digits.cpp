class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int i : nums) {
            int ci = 0;
            while (i != 0) {
                i /= 10;
                ci++;
            }
            if (ci % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};