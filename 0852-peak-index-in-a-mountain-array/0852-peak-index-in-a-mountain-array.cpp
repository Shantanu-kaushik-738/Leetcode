class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int s = 1;
        int l = a.size() - 1;
        while (s <= l) {
            int m = s + (l - s) / 2;
            if (a[m] > a[m - 1] && a[m] > a[m + 1]) {
                return m;
            } else if (a[m - 1] < a[m]) {
                s = m + 1;
            } else {
                l = m - 1;
            }
        }
        return -1;
    }
};