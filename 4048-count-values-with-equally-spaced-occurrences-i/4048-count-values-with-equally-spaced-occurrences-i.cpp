class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int res = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);

        for (auto& i : mp)
            if (i.second.size() == 3)
                if (i.second[1] - i.second[0] == i.second[2] - i.second[1]) res++;
        return res;
    }
};