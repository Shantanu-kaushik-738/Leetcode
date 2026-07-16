class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int end) { // O(n)
        vector<int> temp;
        int i = st, j = mid + 1;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            nums[k + st] = temp[k];
        }
    }

    void helper(vector<int>& nums, int st, int end) {

        if (st < end) {
            int mid = st + (end - st) / 2;
            helper(nums, st, mid);      // left half
            helper(nums, mid + 1, end); // right half
            merge(nums, st, mid, end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        helper(nums, 0, nums.size() - 1);
        return nums;
    }
};