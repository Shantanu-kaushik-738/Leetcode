class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        int res = 0;

        for(int i=0; i<tickets.size(); i++) q.push({tickets[i], i});

        while (!q.empty()) {
            q.front().first--;
            res++;

            if (q.front().first > 0) q.push(q.front()); // tickets remains
            if (q.front().second == k && q.front().first == 0) return res; // (k person && buy all tickets)

            q.pop();
        }
        return res;
    }
};