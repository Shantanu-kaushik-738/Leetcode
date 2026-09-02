class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0, odd = 0;
        for (auto& i : nums1) {
            if (i % 2) odd++;
            else even++;
        }
        if (even == nums1.size() || odd == nums1.size()) return true;
        return true; // mix case nums2 possible with subtraction
    }
};
