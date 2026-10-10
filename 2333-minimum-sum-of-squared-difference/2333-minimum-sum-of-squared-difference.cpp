class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> frq(1e5 + 1); // frq of difference 
        for (int i = 0; i < n; i++) frq[abs(nums1[i] - nums2[i])]++;

        int k = k1 + k2;
        int curr = 1e5; // current differece iterator right to left

        while (curr && k) {
            int cnt = min(frq[curr], k); // operations 
            frq[curr] -= cnt;
            frq[curr - 1] += cnt;

            k -= cnt;
            curr--;
        }

        long long res = 0;
        for (long long i = 1; i <= 1e5; i++) res += (frq[i] * i * i); // difference & its frq
        return res;
    }
};