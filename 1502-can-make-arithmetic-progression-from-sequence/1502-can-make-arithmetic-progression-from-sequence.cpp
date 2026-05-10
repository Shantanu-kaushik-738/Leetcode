class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        if (n == 2) {
            return true;
        }
        int d = arr[1] - arr[0];
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] + d != arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};