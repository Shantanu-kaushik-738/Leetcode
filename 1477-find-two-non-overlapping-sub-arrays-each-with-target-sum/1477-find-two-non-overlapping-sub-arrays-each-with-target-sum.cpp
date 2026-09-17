class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, r = 0;
        int s = 0, len = 1e9;
        int res = 1e9;
        vector<int> idx(n, 1e9);

        while (r < n) {
            s += arr[r];
            while (l < r && s > target) s -= arr[l++];
            if (s == target) {
                if (l && idx[l - 1] != 1e9) res = min(res, (r - l + 1) + idx[l - 1]);
                len = min(len, r - l + 1);
            }
            idx[r] = len;
            r++;
        }
        return res == 1e9 ? -1 : res;
    }
};
