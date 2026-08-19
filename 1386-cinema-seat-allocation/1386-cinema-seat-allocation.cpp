class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rev) {
        unordered_map<int, unordered_set<int>> mp; // row -> booked seat in row

        for (auto& i : rev) mp[i[0]].insert(i[1]);

        int res = (n - mp.size()) * 2; // empty seat

        for (auto& i : mp) {
            auto avl = [&](int p) { // lambda funx to check seat p is avaiable or not
                return i.second.find(p) == i.second.end();
            };

            bool A = avl(2) && avl(3) && avl(4) && avl(5);
            bool B = avl(4) && avl(5) && avl(6) && avl(7);
            bool C = avl(6) && avl(7) && avl(8) && avl(9);

            if (A && C) res += 2;
            else if (A || B || C) res++;
        }
        return res;
    }
};
