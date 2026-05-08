class Solution {
public:
    int compress(vector<char>& chs) {
        int n = chs.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            char ch = chs[i];
            int count = 0;

            while (i < n && chs[i] == ch) {
                count++;
                i++;
            }
            if (count == 1) {
                chs[idx++] = ch;
            } else {
                chs[idx++] = ch;
                string str = to_string(count);

                for (char dig : str) {
                    chs[idx++] = dig;
                }
            }
            i--;
        }
        chs.resize(idx);
        return idx;
    }
};