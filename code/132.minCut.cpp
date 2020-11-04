class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        bool isPalin[n][n];
        int i, j, t;
        for (i = 0; i < n; ++i) {
            for (j = i; j < n; ++j) {
                isPalin[i][j] = false;
            }
        }
        // generate palindrome
        for (t = 0; t < n; ++t) {
            // odd-length
            i = j = t;
            while (i >= 0 && j < n && s[i] == s[j]) {
                isPalin[i][j] = true;
                --i;
                ++j;
            }
            // even-length
            i = t;
            j = t + 1;
            while (i >= 0 && j < n && s[i] == s[j]) {
                isPalin[i][j] = true;
                --i;
                ++j;
            }
        }
        int f[n+1];
        f[0] = 0;
        for (i = 1; i <= n; ++i) {
            f[i] = INT_MAX;
            for (j = 0; j < i; ++j) {
                if (isPalin[j][i - 1]) {
                    f[i] = min(f[j] + 1, f[i]);
                }
            }
        }
        return f[n] - 1;
    }
};