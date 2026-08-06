// class Solution {
// public:
//     vector<int> fpse(vector<int>& nums) {
//         vector<int> pse(nums.size());
//         stack<int> st; // for index

//         for (int i = 0; i < nums.size(); i++) {
//             while (!st.empty() && nums[st.top()] > nums[i]) st.pop();

//             pse[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return pse;
//     }

//     vector<int> fnse(vector<int>& nums) {
//         vector<int> nse(nums.size());
//         stack<int> st; // for index

//         for (int i = nums.size() - 1; i >= 0; i--) {
//             while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();

//             nse[i] = st.empty() ? nums.size() : st.top();
//             st.push(i);
//         }
//         return nse;
//     }
//     int largestRectangleArea(vector<int>& heights) {
//         vector<int> nse = fnse(heights);
//         vector<int> pse = fpse(heights);
//         int res = 0;

//         for (int i = 0; i < heights.size(); i++) {
//             res = max(res, (heights[i] * (nse[i] - pse[i] - 1)));
//         }
//         return res;
//     }
// };
class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int> s;
        int res = 0;
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || nums[i] <= nums[s.top()])) {
                int height = nums[s.top()];
                s.pop();
                int width = (s.empty()) ? i : (i - s.top() - 1);
                res = max(res, height * width);
            }
            s.push(i);
        }
        return res;
    }
};