class Solution {
public:
    int lower(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1; 
        int res = -1;
  
        while (low <= high) { 
            int mid = low + (high - low) / 2;
  
            if (arr[mid] == x) {
                res = mid;
                high = mid - 1;
            } else if (arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        } 
        return res;
    }

    int upper(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1; 
        int res = -1;
  
        while (low <= high) { 
            int mid = low + (high - low) / 2;
  
            if (arr[mid] == x) {
                res = mid;
                low = mid + 1;
            } else if (arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        } 
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower(nums, target);
        if (low == -1) return {-1, -1};
        return {low, upper(nums, target)};
    }
};