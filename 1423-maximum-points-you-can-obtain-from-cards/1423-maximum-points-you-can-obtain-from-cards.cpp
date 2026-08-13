class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int ls = 0, rs = 0; // left, right sum
        for (int i = 0; i < k; i++) ls += nums[i];

        int res = ls;
        int ridx = nums.size() - 1; // right index
        for (int i = k - 1; i >= 0; i--) {
            ls -= nums[i];
            rs += nums[ridx--];
            res = max(res, ls + rs);
        }
        return res;
    }
};