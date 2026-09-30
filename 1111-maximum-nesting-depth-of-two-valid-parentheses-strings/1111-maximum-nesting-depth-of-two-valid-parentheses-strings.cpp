class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int cnt = 0;
        for (auto& i : seq) {
            if (i == '(') {
                cnt++;
                res.push_back((cnt + 1) % 2);
            } else {
                res.push_back((cnt + 1) % 2);
                cnt--;
            }
        }
        return res;
    }
};
