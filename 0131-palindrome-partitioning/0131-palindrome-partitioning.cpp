class Solution {
public:
    bool palindrome(string s) {
        int st = 0, end = s.length() - 1;

        while (st < end) {
            if (s[st++] != s[end--]) {
                return false;
            }
        }
        return true;
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