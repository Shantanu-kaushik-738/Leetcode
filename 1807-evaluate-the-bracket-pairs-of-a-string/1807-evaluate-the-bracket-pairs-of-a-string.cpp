class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        string res = "";
        int i = 0, n = s.size();

        unordered_map<string, string> mp;
        for (auto& i : know) mp[i[0]] = i[1];

        while (i < n) {
            if (isalnum(s[i])) res += s[i];
            else { // find '('
                i++;
                int j = i;
                while (j < n && s[j] != ')') j++;
                res += mp.count(s.substr(i, j - i)) ? mp[s.substr(i, j - i)] : "?";
                i = j;
            }
            i++;
        }
        return res;
    }
};