class Solution {
public:
    int gcdf(int a, int b) {
        while (a && b) {
            if (a < b) b = b % a;
            else a = a % b;
        }
        return (a) ? a : b;
    }

    int findGCD(vector<int>& nums) {
        int mn = 1e9, mx = -1e9;
        for (auto& i : nums) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
        return gcdf(mn, mx);
    }
};