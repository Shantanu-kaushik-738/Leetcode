class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gs = 0, cs = 0;
        int res = 0, curr = 0;

        for (int i = 0; i < gas.size(); i++) {
            gs += gas[i]; cs += cost[i];
            curr += gas[i] - cost[i];
            if (curr < 0) {
                res = i + 1;
                curr = 0;
            }
        }
        return gs < cs ? -1 : res;
    }
};
