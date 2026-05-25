class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (auto& str : strs) {
            string temp = str;
            sort(begin(temp), end(temp));
            mpp[temp].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& str : mpp) {
            ans.push_back(str.second);
        }
        return ans;
    }
};