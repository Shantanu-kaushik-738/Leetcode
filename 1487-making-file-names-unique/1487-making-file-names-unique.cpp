class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mpp;
        vector<string> res;

        for (auto& i : names) {
            if (mpp.find(i) == mpp.end()) {
                res.push_back(i);
                mpp[i] = 1;
            } else {
                int k = mpp[i];
                string p = i + "(" + to_string(k) + ")";

                while (mpp.find(p) != mpp.end()) {
                    k++;
                    p = i + "(" + to_string(k) + ")";
                }
                res.push_back(p);
                mpp[i] = k + 1;
                mpp[p] = 1;
            }
        }
        return res;
    }
};