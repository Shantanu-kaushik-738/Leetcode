class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frq(26);
        for (auto& i : tasks) frq[i - 'A']++;

        int res = 0;
        priority_queue<int> pq; // max heap

        for (auto& i : frq) {
            if (i) pq.push(i);
        }

        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int p = pq.top();
                    pq.pop();
                    p--;
                    temp.push_back(p);
                }
            }
            for (auto& i : temp) {
                if (i) pq.push(i);
            }
            res += (pq.empty()) ? temp.size() : n + 1;
        }
        return res;
    }
};
