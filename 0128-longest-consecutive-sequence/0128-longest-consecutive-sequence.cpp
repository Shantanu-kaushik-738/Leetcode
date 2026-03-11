class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int maxi = 1;
        int cnt = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                continue;
            } else if (nums[i] + 1 == nums[i + 1]) {
                cnt++;
            } else {
                maxi = max(maxi, cnt);
                cnt = 1;
            }
        }
        maxi = max(maxi, cnt);
        return maxi;
    }
};