class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ldr, vector<int>& wst, vector<int>& wdr) {
        int ans = INT_MAX;
        for (int i = 0; i < lst.size(); i++) {
            for (int j = 0; j < wst.size(); j++) {
                int ls = lst[i];  // land open
                int ld = ldr[i];  // land duration
                int lf = ls + ld; // land finish

                int ws = wst[j];       // water open
                int wd = wdr[j];       // water duration
                int was = max(ws, lf); // wait if not open
                int f1 = was + wd;     // total finish {land->water}

                int wf = ws + wd;      // water finish
                int las = max(ls, wf); // wait if not open
                int f2 = las + ld;     // total finish {water->land}

                ans = min(ans, min(f1, f2));
            }
        }
        return ans;
    }
};