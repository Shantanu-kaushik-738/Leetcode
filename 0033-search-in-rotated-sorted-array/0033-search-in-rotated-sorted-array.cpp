class Solution {
public:
    int search(vector<int>& nums, int t) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == t) {
                return mid;
            }

            // left sort
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= t && nums[mid] >= t) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
            // right sort
            else {
                if (nums[mid] <= t && nums[end] >= t) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
