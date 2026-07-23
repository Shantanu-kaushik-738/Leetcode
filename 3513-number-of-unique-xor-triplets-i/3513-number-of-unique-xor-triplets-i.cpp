class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n < 20) {
            set<int> st;
            for (auto& num : nums) st.insert(num);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        st.insert(nums[i] ^ nums[j] ^ nums[k]);
                    }
                }
            }
            return st.size();
        }

        int m = 0;
        while ((1 << m) <= n) m++;
        return (1 << m);
    }
};
