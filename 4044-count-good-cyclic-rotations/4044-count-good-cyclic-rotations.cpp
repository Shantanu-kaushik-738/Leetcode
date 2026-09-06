class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr = nums;
        for (auto& i : nums) arr.push_back(i);

        long long first = 0, second = 0;
        for (int i = 0; i < n / 2; i++) first += arr[i];
        for (int i = n / 2; i < n; i++) second += arr[i];

        int res = 0;
        if (first > second) res++;
        
        for (int i = 1; i < n; i++) {
            first -= arr[i - 1]; // remove first el
            first += arr[i + n / 2 - 1]; // add new from second first

            second -= arr[i + n / 2 - 1]; // remove first el
            second += arr[i + n - 1];

            if (first > second) res++;
        }
        return res;
    }
};
