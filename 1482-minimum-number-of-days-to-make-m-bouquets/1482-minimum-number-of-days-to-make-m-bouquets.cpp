class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day, int n) {
        int cnt = 0;
        int totalb = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                totalb += (cnt / k);
                cnt = 0;
            }
        }
        totalb += (cnt / k);

        return totalb >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            mini = min(bloomDay[i], mini);
            maxi = max(bloomDay[i], maxi);
        }

        if ((long long) m * k > n) {
            return -1;
        }
        int low = mini, high = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, m, k, mid, n)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};