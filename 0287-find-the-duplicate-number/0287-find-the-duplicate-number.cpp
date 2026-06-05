class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sl = nums[0];
        int fs = nums[0];

        do {
            sl = nums[sl];
            fs = nums[nums[fs]];
        } while (sl != fs);

        sl = nums[0];
        while (sl != fs) {
            sl = nums[sl];
            fs = nums[fs];
        }
        return sl;
    }
};