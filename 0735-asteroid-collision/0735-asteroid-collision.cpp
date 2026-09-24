class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> res;

        for (auto& i : ast) {
            if (i > 0) res.push_back(i);
            else {
                while (res.size() && res.back() > 0 && res.back() < abs(i)) res.pop_back();
                if (res.size() && res.back() + i == 0) res.pop_back();
                else if (res.empty() || res.back() < 0) res.push_back(i); 
            }
        }
        return res;
    }
};
