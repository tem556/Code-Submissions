class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int mZero[m];
        int nZero[n];
        memset(mZero, 0, m * sizeof(int));
        memset(nZero, 0, n * sizeof(int));
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (matrix.at(j).at(i) == 0) {
                    mZero[j] = 1;
                    nZero[i] = 1;
                }
            }
        }

        for (int j = 0; j < m; ++j) {
            if (mZero[j]) {
                for (auto& x : matrix.at(j)) {
                    x = 0;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nZero[i]) {
                for (auto& j : matrix) {
                    j.at(i) = 0;
                }
            }
        }
    }
};
