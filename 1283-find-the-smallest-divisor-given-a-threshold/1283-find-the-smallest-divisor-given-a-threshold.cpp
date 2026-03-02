class Solution {
public:
    int sumofD(vector<int>& nums, int n) {
        int sum = 0;
        for (auto v : nums) {
            sum += (v + n - 1) / n;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sumofD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};