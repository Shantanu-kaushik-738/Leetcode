class Solution {
public:
    bool palindrome(string s) {
        string s2 = s;
        reverse(begin(s), end(s));
        return (s == s2);
    }

    void helper(string s, vector<string>& temp, vector<vector<string>>& ans) {
        if (s.length() == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            string part = s.substr(0, i + 1);
            if (palindrome(part)) {
                temp.push_back(part);
                helper(s.substr(i + 1), temp, ans); // recursive call
                temp.pop_back(); // backtracking
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;

        helper(s, temp, ans);
        return ans;
    }
};