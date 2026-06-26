class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int c1 = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    c1++;
                }
                if (c1 > (j - i + 1) / 2) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};