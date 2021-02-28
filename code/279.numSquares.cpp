class Solution {
public:
    int numSquares(int n) {
        int f[n+1];
        f[0] = 0;
        int i, j;
        for (i = 1; i <= n; ++i) {
            f[i] = INT_MAX;
            for (j = 1; j * j <= i; ++j) {
                if (f[i - j * j] + 1 < f[i]) {
                    f[i] = f[i - j * j] + 1;
                }
            }
        }
        return f[n];
    }
};