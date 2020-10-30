class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> f(2, vector<int>(rowIndex + 1));
        for (int i = 0; i <= rowIndex; i++) {
            f[i & 1][0] = f[i & 1][i] = 1;
            for (int j = 1; j < i; j++) {
                f[i & 1][j] = f[i - 1 & 1][j - 1] + f[i - 1 & 1][j]; 
            }
        }
        return f[rowIndex & 1];
    }
}