class Solution {
public:
    int minQueenMoves(vector<int>& sc, vector<int>& tr) {
        if (sc[0] == tr[0] && sc[1] == tr[1]) return 0;
        if (abs(sc[0] - tr[0]) == abs(tr[1] - sc[1]) || sc[0] == tr[0] || sc[1] == tr[1]) return 1;
        return 2;
    }
};
