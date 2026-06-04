class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        int i1 = 0;
        while (i < n - 1 && nums[i] < nums[i + 1]) {
            i++;
            i1++;
        }

        int d = 0;
        while (i < n - 1 && nums[i] > nums[i + 1]) {
            i++;
            d++;
        }

        int i2 = 0;
        while (i < n - 1 && nums[i] < nums[i + 1]) {
            i++;
            i2++;
        }
        return (i == n - 1 && i1 > 0 && d > 0 && i2 > 0);
    }
};