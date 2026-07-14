class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(begin(nums), end(nums), [&](string a, string b) { // descending
            if (a.length() != b.length())
                return a.length() > b.length(); // larger string == larger number
            return a > b;          // same length compare first number
        });
        return nums[k - 1];
    }
};