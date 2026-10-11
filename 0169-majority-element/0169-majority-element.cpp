class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int frq = 0, res;
        for (auto& i : nums) {
            if (!frq) res = i;
            if (i == res) frq++;
            else frq--;    
        }
        return res;
    }
};
