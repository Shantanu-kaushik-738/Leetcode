class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (auto& j : nums) if (j != val) nums[i++] = j;
        return i;
    }
};
