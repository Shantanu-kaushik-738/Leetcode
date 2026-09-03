class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int evn = 0, od = 0;
        int mini = 1e9;

        for (auto& i : nums1) {
            if (i % 2) od++;
            else evn++;
            mini = min(mini, i);
        }

        if (evn == nums1.size() || od == nums1.size()) return true;

        bool odd = true, even = true;

        for (auto& i : nums1) { // for even
            if ((i % 2) || (i - mini) % 2) { // original construct both are odd
                even = false;
                break;
            }
        }

        for (auto& i : nums1) { // for odd
            if (!((i % 2) || (i - mini) % 2)) { // original construct both are even
                odd = false;
                break;
            }
        }
        return odd || even;
    }
};
