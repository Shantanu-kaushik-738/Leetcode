class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) s.push_back(asteroids[i]);
            else {
                while (!s.empty() && s.back() > 0 && s.back() < abs(asteroids[i])) s.pop_back();
                if (!s.empty() && asteroids[i] + s.back() == 0) s.pop_back(); // same size are explode
                else if (s.empty() || s.back() < 0) s.push_back(asteroids[i]);
            }
        }
        return s;
    }
};