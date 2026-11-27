class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto& i : nums) {
            int p = abs(i);
            if (nums[p - 1] > 0) nums[p - 1] = -nums[p - 1];
            else return p;
        }
        return 0;
    }
};
