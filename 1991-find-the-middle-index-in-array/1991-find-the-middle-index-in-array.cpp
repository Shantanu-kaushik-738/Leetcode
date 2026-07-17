class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int s = 0; // total sum
        for (auto& i : nums) s += i;

        int ls = 0; // left sum
        for (int i = 0; i < nums.size(); i++) {
            int rs = s - ls - nums[i]; // right sum
            if (ls == rs) return i;
            ls += nums[i];
        }
        return -1;
    }
};