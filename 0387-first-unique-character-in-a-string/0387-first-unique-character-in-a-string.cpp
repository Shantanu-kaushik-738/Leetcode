class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        queue<int> q;

        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                q.push(i);
            }
            mp[s[i]]++;
            while (q.size() && mp[s[q.front()]] > 1) q.pop();
        }
        return q.size() ? q.front() : -1;
    }
};
