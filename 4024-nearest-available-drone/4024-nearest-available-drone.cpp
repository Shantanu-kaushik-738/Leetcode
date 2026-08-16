class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int tx = target[0], ty = target[1];
        int ans = -1;
        int mini = 1e9;

        for (int i = 0; i < drones.size(); i++) {
            int x = drones[i][0], y = drones[i][1], r = drones[i][2];
            int d = abs(x - tx) + abs(y - ty);

            if (d <= r) {
                if (d < mini || (d == mini && i < ans)) {
                    mini = d;
                    ans = i;
                }
            }
        }
        return ans;
    }
};