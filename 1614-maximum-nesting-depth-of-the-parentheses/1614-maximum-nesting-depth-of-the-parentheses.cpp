class Solution {
public:
    int maxDepth(string s) {
        int res = 0, curr = 0;
        for (auto& i : s) 
            if (i == '(') {
                curr++;
                res = max(res, curr);
            } else if (i == ')') curr--;
        return res;
    }
};
