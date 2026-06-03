class Solution {
private: 
    int findtime(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2) {
        int f1 = 1e9;
        for (int i = 0; i < s1.size(); i++) {
            f1 = min(f1, s1[i] + d1[i]);
        }

        int f2 = 1e9;
        for (int i = 0; i < s2.size(); i++) {
            f2 = min(f2, max(f1, s2[i]) + d2[i]);
        }
        return f2;
    }

public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {

        int r1 = findtime(ls,ld,ws,wd);
        int r2 = findtime(ws,wd,ls,ld);

        return min(r1, r2);
    }
};