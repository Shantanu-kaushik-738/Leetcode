class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mpp;
        int cnt = 0;

        for (auto& c : word) {
            mpp[c]++;
        }

        for (auto& i : mpp) {
            char c = i.first;

            if (islower(c)) {
                if (mpp.find(c - 32) != mpp.end()) {
                    cnt++;
                }
            } else {
                if (mpp.find(c + 32) != mpp.end()) {
                    cnt++;
                }
            }
        }
        return cnt / 2;
    }
};