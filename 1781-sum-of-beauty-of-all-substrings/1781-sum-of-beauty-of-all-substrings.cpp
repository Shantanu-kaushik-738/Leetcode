class Solution {
private:
    int max_el(vector<int> nums) {
        int mx = -1e9;
        for (auto i : nums) {
            if (i > mx && i > 0) {
                mx = i;
            }
        }
        return mx;
    }

private:
    int min_el(vector<int> nums) {
        int mn = 1e9;
        for (auto i : nums) {
            if (i < mn && i > 0) {
                mn = i;
            }
        }
        return mn;
    }

public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> alp(26, 0);
            for (int j = i; j < n; j++) {
                alp[s[j] - 'a']++;

                int mx = max_el(alp);
                int mn = min_el(alp);

                ans += mx - mn;
                ;
            }
        }
        return ans;
    }
};