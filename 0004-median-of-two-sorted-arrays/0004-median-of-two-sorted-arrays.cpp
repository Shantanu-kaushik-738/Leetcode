class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        vector<int> res;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) res.push_back(nums1[i++]);
            else res.push_back(nums2[j++]);
        }

        while (i < n) res.push_back(nums1[i++]);
        while (j < m) res.push_back(nums2[j++]);

        if ((n + m) % 2) return res[(n + m) / 2];
        return (res[(n + m) / 2] + res[((n + m) / 2) - 1]) / 2.0;
    }
};