class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (auto& i : asteroids) {
            if (ans.empty() || (ans.back() < 0 && i < 0) || (ans.back() > 0 && i > 0)) ans.push_back(i);
            else {
                while (ans.size() && i < 0 && ans.back() > 0 && ans.back() < abs(i)) ans.pop_back();
                if (ans.size() && i < 0 && ans.back() > 0 && ans.back() == abs(i)) ans.pop_back();
                else if (ans.empty() || ans.back() < 0) ans.push_back(i);
            }
        }
        return ans;
    }
};
