class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto ch : words) {
            int st = 0;
            int end = ch.size() - 1;
            bool fl = true;

            while (st <= end) {
                if (ch[st] != ch[end]) {
                    fl = false;
                }
                st++;
                end--;
            }
            if (fl) {
                return ch;
            }
        }
        return "";
    }
};