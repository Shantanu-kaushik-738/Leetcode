class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;

        string s = to_string(n);
        for (auto& i : s) {
            if (i != '0') {
                sum += i - '0';
                num = num * 10 + (i - '0');
            }
        }
        return sum * num;
    }
};