class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int orn = x;
        long long r = 0;
        while (x != 0) {
            int d = x % 10;
            r = r * 10 + d;
            x /= 10;
        }
        long long rn = r;
        return rn == orn ;
    }
};