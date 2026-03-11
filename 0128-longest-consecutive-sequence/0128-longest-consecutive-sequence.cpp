class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int n = nums.size();
        int lng = 1;

        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        
        for (auto v : st) {
            if (st.find(v - 1) == st.end()) {
                int cnt = 1;
                int x = v;
                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }
                lng = max(lng, cnt);
            }
        }
        return lng;
    }
};