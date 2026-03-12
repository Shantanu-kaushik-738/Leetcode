class Solution {
public:
    int subarraySum(vector<int>& nums, int x) {
        int n = nums.size();
        map<int, int> mpp;
        mpp[0] = 1;
        int cnt = 0;
        int ps = 0;

        for (int i = 0; i < n; i++) {
            ps += nums[i];
            int r = ps - x;
            cnt += mpp[r];
            mpp[ps]++;
        }
        return cnt;
    }
};