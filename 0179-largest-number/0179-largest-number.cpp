class Solution {
public:
    static bool compare(int& i, int& j) {
        string s1 = to_string(i);
        string s2 = to_string(j);

        return (s1 + s2 > s2 + s1);
    }

    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(begin(nums), end(nums), compare);

        for (auto& i : nums) {
            ans += to_string(i);
        }
        if (ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};