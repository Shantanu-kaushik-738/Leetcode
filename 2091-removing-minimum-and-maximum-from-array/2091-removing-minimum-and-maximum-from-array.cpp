class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int l = 0, r = 0;
        int mini = *min_element(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mini) l = i;
            else if (nums[i] == maxi) r = i;
        }

        int front = max(l, r) + 1;
        int back = nums.size() - min(l, r);
        int both = (min(l, r) + 1) + (nums.size() - max(l, r));

        return min({front, back, both});
    }
};
