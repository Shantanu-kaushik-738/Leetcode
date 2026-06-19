class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int h = 0;
        int a = 0;
        for (auto& i : gain) {
            h = max(h, (a += i));
        }
        return h;
    }
};