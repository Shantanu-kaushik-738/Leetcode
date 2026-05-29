class Solution {
public:
    int minElement(vector<int>& nums) {

        for (auto& i : nums) {
            int temp = 0;

            while (i != 0) {
                temp += i % 10;
                i /= 10;
            }
            i = temp;
        }
        return *min_element(nums.begin(), nums.end());
    }
};