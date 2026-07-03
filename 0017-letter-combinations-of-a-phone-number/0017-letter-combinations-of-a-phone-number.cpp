class Solution {
public:
    unordered_map<char, string> mp;

    void helper(int i, string digits, string s, vector<string>& res) {
        if (i == digits.length()) {
            res.push_back(s);
            return;
        }

        char c = digits[i];
        string str = mp[c];

        for (int j = 0; j < str.length(); j++) {
            s.push_back(str[j]);
            helper(i + 1, digits, s, res);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        helper(0, digits, "", res);
        return res;
    }
};