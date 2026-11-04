class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> frq(26);
        for (auto& i : s) frq[i - 'a']++;
        for (auto& i : t) frq[i - 'a']--;
        for (auto& i : frq) if (i) return false;
        return true;
    }
};