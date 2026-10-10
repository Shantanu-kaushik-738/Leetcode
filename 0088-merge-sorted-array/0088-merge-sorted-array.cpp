class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i = n + m - 1;
        n--, m--;
        while (n >= 0 && m >= 0) 
            if (nums1[n] > nums2[m]) nums1[i--] = nums1[n--];
            else nums1[i--] = nums2[m--];

        while (n >= 0) nums1[i--] = nums1[n--];
        while (m >= 0) nums1[i--] = nums2[m--];
    }
};
