class Solution {
public:
    bool isValid(string word) {
        int v = 0, c = 0;

        if (word.length() < 3) {
            return false;
        }

        for (auto& i : word) {
            if (isdigit(i)) {
                continue;
            } else if (isalpha(i)) {
                if (tolower(i) == 'a' || tolower(i) == 'e' ||
                    tolower(i) == 'i' || tolower(i) == 'o' ||
                    tolower(i) == 'u') {
                    v++;
                } else {
                    c++;
                }
            } else {
                return false;
            }
        }
        return (v && c);
    }
};