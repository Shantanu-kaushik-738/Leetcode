class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for (auto& x : arr1) {
            while ((!st.count(x)) && (x != 0)) {
                st.insert(x);
                x /= 10;
            }
        }
        int cnt = 0;

        for (auto& x : arr2) {
            while ((!st.count(x)) && (x != 0)) {
                x /= 10;
            }
            if (x > 0) {
                cnt = max(cnt, (int)log10(x) + 1);
            }
        }
        return cnt;
    }
};