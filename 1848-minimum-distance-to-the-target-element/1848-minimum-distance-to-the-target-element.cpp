class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int d = INT_MAX;

        if (n == 1) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                d = min(d, abs(start - i));
            }
        }
        return d;
    }
};