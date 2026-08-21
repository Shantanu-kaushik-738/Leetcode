class Solution {
public:
    typedef long long ll;
    ll funx(ll mid, vector<int>& coins) {
        ll cnt = 0;
        int n = coins.size();

        for (int ex = 1; ex <= (1 << n) - 1; ex++) { // i <= 2 ^ n - 1
            ll lcm = 0;
            ll p = 0;

            for (int i = 0; i < n; i++) {
                if (ex & (1 << i)) {
                    p++;
                    if (lcm == 0) lcm = coins[i];
                    else lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                }
            }
            if (p % 2 == 0) cnt -= mid / lcm;
            else cnt += mid / lcm;
        }
        return cnt;
    }

    ll findKthSmallest(vector<int>& coins, int k) {
        ll res = -1;
        ll l = 1;
        ll r = (ll)(*max_element(begin(coins), end(coins))) * k;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (funx(mid, coins) >= k) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return res;
    }
};
