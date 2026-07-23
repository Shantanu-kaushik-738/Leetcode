class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int a = 1;
        if (nums.size() < 3) return nums.size();
        else {
            while (a <= nums.size()) a *= 2;
        }
        return a;
    }
};
