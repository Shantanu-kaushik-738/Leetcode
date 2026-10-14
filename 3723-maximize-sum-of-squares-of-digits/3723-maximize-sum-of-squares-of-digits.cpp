class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        for (int i = 0; i < num; i++) {
            int d = min(9, sum);
            res += d + '0';
            sum -= d;
        }
        return sum ? "" : res;
    }
};
