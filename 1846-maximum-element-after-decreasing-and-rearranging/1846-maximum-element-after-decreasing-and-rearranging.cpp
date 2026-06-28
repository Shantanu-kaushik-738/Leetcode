class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int ans = 0;
        for (auto& i : arr) {
            if (ans + 1 <= i) {
                ans++;
            }
        }
        return ans;
    }
};