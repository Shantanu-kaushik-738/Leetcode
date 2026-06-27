class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mpp;
        for (auto& i : nums) mpp[i]++;

        int ans = 0;
        if (mpp[1] % 2 == 0) ans = mpp[1] - 1;
        else ans = mpp[1];
        mpp.erase(1);

        for (auto& i : mpp) {
            int len = 0;
            long long j = i.first;

            while (mpp.count(j) && mpp[j] > 1) {
                j *= j;
                len += 2;
            }
            ans = max(ans, len + (mpp.count(j) ? 1 : -1));
        }
        return ans;
    }
};