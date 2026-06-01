class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(begin(nums), end(nums));
        int pvt = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pvt = i;
                break;
            }
        }

        if (pvt == -1) {
            reverse(begin(nums), end(nums));
            return;
        }

        for (int i = n - 1; i > pvt; i--) {
            if (nums[i] > nums[pvt]) {
                swap(nums[i], nums[pvt]);
                break;
            }
        }

        // reverse(begin(nums) + pvt + 1, end(nums));
        int i = pvt + 1;
        int j = n - 1;
        while (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};