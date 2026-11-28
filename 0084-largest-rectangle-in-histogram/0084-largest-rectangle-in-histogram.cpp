class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = ssize(nums);
        stack<int> s;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int num = (i == n) ? 0 : nums[i];
            while (ssize(s) && nums[s.top()] > num) {
                int h = nums[s.top()];
                s.pop();
                int w = (ssize(s)) ? (i - s.top() - 1) : i;
                ans = max(ans, h * w);
            }
            s.push(i);
        }
        return ans;
    }
};