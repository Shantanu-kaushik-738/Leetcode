class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        sort(begin(nums), end(nums));

        unordered_map<int, int> st;
        int r = 1;

        for (auto& i : nums) {
            if (!st.count(i)) {
                st[i] = r++;
            }
        }

        for (auto& i : arr) {
            i = st[i];
        }
        return arr;
    }
};