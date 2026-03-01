class Solution {
public:
    int fmax(vector<int> arr) {
        int mx = 0;

        for (int i = 0; i < arr.size(); i++) {
            mx = max(mx, arr[i]);
        }
        return mx;
    }

    long long hour(vector<int>& arr, int mid) {
        long long thr = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            thr += (long long)ceil((double)arr[i] / (double)mid);
        }
        return thr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int m = piles.size();
        long long end = fmax(piles); // maximum element
        int ans = 0;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            long long thr =
                hour(piles, mid); //(banana per hour(banana/hour))*total hour

            if (thr <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};