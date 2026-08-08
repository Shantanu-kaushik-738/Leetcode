class StockSpanner {
public:
    stack<pair<int, int>> s;
    int ind = 0;
    StockSpanner() { ind = 0; }

    int next(int price) {
        ind++;
        while (!s.empty() && s.top().first <= price) s.pop();

        int res = ind - (s.empty() ? 0 : s.top().second);
        s.push({price, ind});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */