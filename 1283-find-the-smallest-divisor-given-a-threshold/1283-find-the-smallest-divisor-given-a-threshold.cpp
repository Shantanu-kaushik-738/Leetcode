class Solution {
public:
    int sumofD(vector<int>& nums, int n) {
        int sum = 0;
        for (auto v : nums) {
            sum += ceil((double)v / n);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());
        int low = 1;
        int high = maxi;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sumofD(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};