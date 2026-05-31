class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));

        long long mss = mass;
        for (auto& a : asteroids) {
            if (a <= mss) {
                mss += a;
            } else {
                return false;
            }
        }
        return true;
    }
};