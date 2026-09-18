class Solution {
public:

vector<string> maxNumOfSubstrings(string s) {
    const int size = s.size();
    vector<int> first(26, -1);
    vector<int> last(26, -1);
    vector<int> freq(26);
    vector<int> order;

    for (int i = 0; i < size; i++) {
        int ch = s[i] - 'a';

        if (first[ch] == -1) {
            first[ch] = i;
            order.push_back(ch);
        }
        last[ch] = i;
        freq[ch]++;
    }
    vector<string> ans;
    deque<array<int, 3>> dq;

    for (const int& ch: order) {
        dq.push_front({first[ch], last[ch], freq[ch]});

        int left = INT_MAX;
        int right = INT_MIN;
        int len = 0;

        for (const auto &[l, r, c]: dq) {
            left = min(left, l);
            right = max(right, r);
            len += c;
            if (len == right - left + 1) {
                break;
            }
        }
        if (len == right - left + 1) {
            ans.emplace_back(s.substr(left, len));
            dq.clear();
        }
    }
    return ans;
}
};