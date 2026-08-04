class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(begin(nums), end(nums));
        int mx = *max_element(begin(nums), end(nums));

        vector<int> res;
        for (int i = mn; i <= mx; i++) {
            if (count(begin(nums), end(nums), i) == 0) res.push_back(i);
        }
        return res;
    }
};