class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if (hand.size() % k) return false;

        map<int, int> mp;
        for (auto& i : hand) mp[i]++;

        while (!mp.empty()) {
            int p = mp.begin()->first;
            for (int i = 0; i < k; i++) {
                if (!mp[p + i]) return false;

                mp[p + i]--;
                if (!mp[p + i]) mp.erase(p + i);
            }
        }
        return true;
    }
};
