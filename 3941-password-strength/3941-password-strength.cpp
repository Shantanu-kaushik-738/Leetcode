class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        unordered_set<char> stt;

        for (auto& st : password) {
            if (stt.count(st)) {
                continue;
            }
            stt.insert(st);

            if (st >= 'a' && st <= 'z') {
                ans++;
            } else if (st >= 'A' && st <= 'Z') {
                ans += 2;
            } else if (st >= '0' && st <= '9') {
                ans += 3;
            } else {
                ans += 5;
            }
        }
        return ans;
    }
};