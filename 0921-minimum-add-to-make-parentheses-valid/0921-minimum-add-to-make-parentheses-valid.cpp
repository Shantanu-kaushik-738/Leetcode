class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, cnt2 = 0;
        for (auto& i : s) 
            if (i == '(') cnt++;
            else if (!cnt) cnt2++; // balanced () but extra )
            else cnt--;
        return cnt + cnt2;
    }
};
