class Solution {
public:
    bool funx(vector<int> v1, vector<int> v2) {
        for (int i = 0; i < 26; i++) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> frq(26, 0);
        for (auto& i : s1)
            frq[i - 'a']++;

        for (int i = 0; i < s2.length(); i++) {
            int wi = 0, idx = i;
            vector<int> wfrq(26, 0);

            while (wi < s1.length() && idx < s2.length()) {
                wfrq[s2[idx++] - 'a']++;
                wi++;
            }
            if (funx(wfrq, frq)) return true;
        }
        return false;
    }
};
