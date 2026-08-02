class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> res;
        stack<int> s;

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) s.push(asteroids[i]);
            else {
                while (!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])) s.pop();
                if (!s.empty() && asteroids[i] + s.top() == 0) s.pop(); // same size are explode
                else if (s.empty() || s.top() < 0) s.push(asteroids[i]);
            }
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};