class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        s = ' ' + s, t = ' ' + t;
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1));
        for (int i = 0; i <= n; i++) f[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = f[i - 1][j];
                if (s[i]  == t[j]) f[i][j] += f[i - 1][j - 1];
            }
        }
        return f[n][m];
    }
};