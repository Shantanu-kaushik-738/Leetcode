class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int res = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);

        for (auto& i : mp) {
            if (i.second.size() >= 3) {
                int p = i.second[1] - i.second[0];
                bool f = true;
                for (int j = 2; j < i.second.size(); j++) {
                    if (i.second[j] - i.second[j - 1] != p) {
                        f = false;
                        break;
                    }
                }
                if (f) res++;
            }
        }
        return res;
    }
};