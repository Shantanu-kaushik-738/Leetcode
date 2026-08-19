class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rev) {
        unordered_map<int, int> mp; // row -> booked seat in row

        for (auto& i : rev) mp[i[0]] |= (1 << i[1]); // or opration 

        int res = (n - mp.size()) * 2; // empty seat

        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto& i : mp) {
            
            bool A = (maskA & i.second) == 0;
            bool B = (maskB & i.second) == 0;
            bool C = (maskC & i.second) == 0;

            if (A && C) res += 2;
            else if (A || B || C) res++;
        }
        return res;
    }
};
