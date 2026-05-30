class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums;

        for (int i = 1; i <= 9; i++) {
            int num = i;
            int j = i + 1;

            while (num <= high && j <= 9) {
                num = num * 10 + j;

                if (low <= num && num <= high) {
                    nums.push_back(num);
                }
                j++;
            }
        }
        sort(begin(nums), end(nums));
        return nums;
    }
};