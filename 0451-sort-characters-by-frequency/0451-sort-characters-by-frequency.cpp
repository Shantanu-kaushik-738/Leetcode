class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++;
        }

        vector<pair<int, char>> v;
        for (auto it : mpp) {
            v.push_back({it.second, it.first});
        }

        sort(rbegin(v), rend(v));

        string ans = "";
        for (auto it : v) {
            ans += string(it.first, it.second);
        }
        return ans;
    }
};
