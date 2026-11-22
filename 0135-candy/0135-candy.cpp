class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        int sum = 1, i = 1;
        while (i < n) {
            if (nums[i] == nums[i - 1]) { sum++; i++; continue; }
            int p = 1;
            while (i < n && nums[i] > nums[i - 1]) {
                p++, i++;
                sum += p;
            }
            int d = 1;
            while (i < n && nums[i] < nums[i - 1]) {
                sum += d;
                d++, i++;
            }
            if (d >= p) sum += d - p;
        }
        return sum;
    }
};
