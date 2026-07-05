class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int mx = 0;

        vector<int> r;
        for (auto& i : nums) {
            int l = -1e9;
            int s = 1e9;
            int t = i;

            while (t > 0) {
                l = max(l, (t % 10));
                s = min(s, (t % 10));
                t /= 10;
            }
            r.push_back(l - s);
            mx = max(mx, l - s);
        }
        int sm = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (r[i] == mx) {
                sm += nums[i];
            }
        }
        return sm;
    }
};