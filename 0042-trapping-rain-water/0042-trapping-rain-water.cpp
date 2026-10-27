class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = height[l], rmax = height[r];

        int ans = 0;
        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (height[l] <= height[r]) ans += min(lmax, rmax) - height[l++];
            else ans += min(lmax, rmax) - height[r--];
        }
        return ans;
    }
};