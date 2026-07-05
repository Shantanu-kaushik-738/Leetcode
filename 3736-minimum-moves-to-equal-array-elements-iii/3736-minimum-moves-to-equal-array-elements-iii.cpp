class Solution {
public:
    int minMoves(vector<int>& nums) {
        int l = *max_element(begin(nums), end(nums));
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            res += l - nums[i];
        }
        return res;
    }
};