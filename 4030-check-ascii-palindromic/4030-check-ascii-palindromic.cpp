class Solution {
public:
    bool isPalindromic(string s) {
        string p = "";
        for (auto& i : s) {
            bitset<8> b((int)i);
            p += b.to_string();
        }
        
        int l = 0, r = p.length() - 1;
        while (l < r) {
            if (p[l] != p[r]) return false;
            l++; r--;
        }
        return true;
    }
};