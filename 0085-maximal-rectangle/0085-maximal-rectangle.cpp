class Solution {
public:
    vector<int> fpse(vector<int>& nums) {
        vector<int> pse(nums.size());
        stack<int> st; // for index

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> fnse(vector<int>& nums) {
        vector<int> nse(nums.size());
        stack<int> st; // for index

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            nse[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = fnse(heights);
        vector<int> pse = fpse(heights);
        int res = 0;

        for (int i = 0; i < heights.size(); i++) {
            res = max(res, (heights[i] * (nse[i] - pse[i] - 1)));
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            res = max(res, area);
        }
        return res;
    }
};