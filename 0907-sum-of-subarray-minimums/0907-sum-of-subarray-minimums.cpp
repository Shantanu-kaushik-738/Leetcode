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

    int sumSubarrayMins(vector<int>& nums) {
        vector<int> nse = fnse(nums);
        vector<int> pse = fpse(nums);

        int m = (int)(1e9 + 7), sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int left = i - pse[i], right = nse[i] - i;

            sum = (sum + (left * right * 1LL * nums[i]) % m) % m;
        }
        return sum;
    }
};
