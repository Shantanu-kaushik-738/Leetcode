class Solution {
public:
    char mid = '0';
    int half = 0;
    string res = "";

    bool funx(string& curr, vector<int>& frq, string& target, int i, bool greater) {
        if (curr.length() == half) {
            string l = curr; // left half
            string r = curr; // right half
            
            reverse(begin(r), end(r));
            if (mid != '0') l += mid;
            l += r;

            if (l > target) {
                res = l;
                return true;
            }
            return false;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (!frq[c - 'a']) continue; // not available
            if (!greater && c < target[i]) continue; // smaller then target

            curr += c;
            frq[c - 'a']--;

            bool gc = (greater || c > target[i]); // check current char > target[i]

            if (funx(curr, frq, target, i + 1, gc)) return true;
            curr.pop_back();
            frq[c - 'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        vector<int> frq(26);
        for (auto& i : s) frq[i - 'a']++;

        int odd = 0; // count odd frequency
        for (int i = 0; i < 26; i++) {
            if (frq[i] % 2) {
                odd++;
                mid = char(i + 'a');
            }
        }

        if (odd > 1) return ""; //  palindrome not possible

        for (auto& i : frq) i /= 2; // for left half
        half = n / 2;

        string curr; // left half
        funx(curr, frq, target, 0, false);
        return res;
    }
};
