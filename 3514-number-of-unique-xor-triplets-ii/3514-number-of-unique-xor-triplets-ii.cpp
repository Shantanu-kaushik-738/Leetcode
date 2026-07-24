class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st, st2;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) st.insert(nums[i] ^ nums[j]);
        }

        for (int i = 0; i < nums.size(); i++) {
            for (auto& j : st) st2.insert(nums[i] ^ j);
        }
        return st2.size();
    }
};