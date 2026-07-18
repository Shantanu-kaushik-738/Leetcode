class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = 1e9, mx = -1e9;
        for (auto& i : nums) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
        return gcd(mn, mx);
    }
};