class Solution {
public:
    bool searchRow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int st = 0, e = n - 1;
        while (st <= e) {
            int mid = st + (e - st) / 2;
            if (target == matrix[row][mid]) {
                return true;
            } else if (target > matrix[row][mid]) {
                st = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int str = 0, er = m - 1;
        while (str <= er) {
            int mr = str + (er - str) / 2;
            if (target >= matrix[mr][0] && target <= matrix[mr][n - 1]) {
                return searchRow(matrix, target, mr);
            } else if (target > matrix[mr][n - 1]) {
                str = mr + 1;
            } else {
                er = mr - 1;
            }
        }
        return false;
    }
};