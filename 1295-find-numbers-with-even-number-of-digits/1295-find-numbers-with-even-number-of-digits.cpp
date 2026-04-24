class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int i : nums) {
            int ci = 0;
            while (i != 0) {
                int d = i % 10;
                ci++;
                i /= 10;
            }
            if (ci % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};