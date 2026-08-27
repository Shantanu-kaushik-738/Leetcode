class Solution {
public:
    string res = "";

    bool funx(string& curr, vector<int>& frq, string& target, int i, bool greater) {
        if (i == target.length()) {
            if (greater) {
                res = curr;
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

    string lexGreaterPermutation(string s, string target) {
        vector<int> frq(26);
        for (auto& i : s) frq[i - 'a']++;

        string curr = "";
        funx(curr, frq, target, 0, false);
        return res;
    }
};
