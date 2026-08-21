class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if (hand.size() % k) return false;
        unordered_map<int, int> frq;
        for (auto& i : hand) frq[i]++;

        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (auto& i : frq) pq.push(i.first);

        while (!pq.empty()) {
            int p = pq.top();

            if (frq[p] == 0) {
                pq.pop();
                continue;
            }

            for (int j = 0; j < k; j++) {
                if (!frq[p + j]) return false;
                frq[p + j]--;
            }
        }
        return true;
    }
};
