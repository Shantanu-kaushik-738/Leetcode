class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            sum += (27 - ((int)s[i] - 'a' + 1)) * (i + 1);
        }
        return sum;
    }
};