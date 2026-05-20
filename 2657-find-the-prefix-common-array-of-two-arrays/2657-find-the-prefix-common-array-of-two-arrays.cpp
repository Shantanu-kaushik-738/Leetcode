class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& nums, vector<int>& arr) {
        int n = nums.size();
        vector<int> ans;
        int cnt = 0;

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;

            if (mpp[nums[i]] == 2) {
                cnt++;
            }
            mpp[arr[i]]++;
            if (mpp[arr[i]] == 2) {
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};