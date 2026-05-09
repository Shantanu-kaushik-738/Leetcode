class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        bool fl = false;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                fl = true;
                int r = (i - startIndex + n) % n;
                int l = (startIndex - i + n) % n;
                ans = min(ans, min(r, l));
            }
        }
        return fl ? ans : -1;
    }
};