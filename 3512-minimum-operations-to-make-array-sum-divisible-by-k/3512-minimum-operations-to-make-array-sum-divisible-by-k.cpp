class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sm = 0;
        for (int i : nums) {
            sm += i;
        }
        if (sm % k == 0) {
            return 0;
        }

        int cnt = 0;

        while (sm % k != 0) {
            sm--;
            cnt++;
        }
        return cnt;
    }
};