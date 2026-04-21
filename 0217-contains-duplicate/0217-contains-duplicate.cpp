class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> frq;
        
        for (auto v : nums) {
            frq[v]++;
            if (frq[v] > 1) {
                return true;
            }
        }
        return false;
    }
};