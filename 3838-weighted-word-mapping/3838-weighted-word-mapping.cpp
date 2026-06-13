class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto& ch : words) {
            int s = 0;
            for (auto& c : ch) {
                s += weights[c - 'a'];
            }
            s %= 26;
            ans += ('z' - s);
        }
        return ans;
    }
};