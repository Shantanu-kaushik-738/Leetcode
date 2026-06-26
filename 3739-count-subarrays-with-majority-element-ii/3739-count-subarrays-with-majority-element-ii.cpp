class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int p = n + 1;
        long long cnt = 0;

        vector<int> freq(2 * n + 2);
        vector<int> pre(2 * n + 2);

        freq[p] = 1;
        pre[p] = 1;

        for (auto& i : nums) {
            p += (i == target ? 1 : -1);
            freq[p]++;

            pre[p] = pre[p - 1] + freq[p];
            cnt += pre[p - 1];
        }
        return cnt;
    }
};