class Solution {
public:
    int midx(vector<vector<int>>& mat, int n, int col) {
        int m = -1;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > m) {
                m = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;
        while (low <= high) {

            int mid = (low + high) / 2;
            int mi = midx(mat, n, mid);

            int left = mid - 1 >= 0 ? mat[mi][mid - 1] : -1;
            int right = mid + 1 < m ? mat[mi][mid + 1] : -1;

            if (mat[mi][mid] > left && mat[mi][mid] > right) {
                return {mi, mid};

            } else if (mat[mi][mid] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};