class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int len = o.size();
        if (!len) return 0;
        int m = o[0].size();

        vector<vector<int>> f(len, vector<int>(m));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < m; j++) {
                if (!o[i][j]) {
                    if (!i && !j) f[i][j] = 1;
                    else {
                        if (i) f[i][j] += f[i - 1][j];
                        if (j) f[i][j] += f[i][j - 1];
                    }
                }
            }
        }
        return f[len - 1][m - 1];
    }
};