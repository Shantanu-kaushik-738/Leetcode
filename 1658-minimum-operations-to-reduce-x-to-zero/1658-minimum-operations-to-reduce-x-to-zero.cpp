class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> mp; // < sum , idx >
        int sum = 0;
        
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }

        if (sum < x) return -1;

        int target = sum - x;
        int len = -1e9;

        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int p = sum - target;

            if (mp.count(p)) len = max(len, i - mp[p]);
        }
        return len == -1e9 ? -1 : n - len;
    }
};
