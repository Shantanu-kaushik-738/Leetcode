class Solution {
public:
    int maximumGap(string skl, string st) {
        int res = 0;
        vector<int> left(skl.size()), right(skl.size());

        int j = 0;
        for (int i = 0; i < skl.size(); i++) {
            while (st[j] != skl[i]) j++;
            left[i] = j;
            j++;
        }

        j = st.size() - 1;
        for (int i = skl.size() - 1; i >= 0; i--) {
            while (st[j] != skl[i]) j--;
            right[i] = j;
            j--;
        }

        for (int i = 1; i < skl.size(); i++) {
            res = max(res, right[i] - left[i - 1]);
        }
        return res;
    }
};