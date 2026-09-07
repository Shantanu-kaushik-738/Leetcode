class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;
        int p = 1;

        for (auto& i : nums) 
            if (i) p *= i;
            else zero++;

        for (auto& i : nums) 
            if (zero > 1) i = 0;
            else if (i && zero) i = 0;
            else if (i) i = p / i;
            else i = p;

        return nums;
    }
};
