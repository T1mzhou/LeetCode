class Solution {
public:
    int Min(int a, int b, int c) {
        return min(a, min(b, c));
    }
    int minDistance(string word1, string word2) {
        if (word1.empty() && word2.empty()) return 0;
        int m = word1.length() + 1;
        int n = word2.length() + 1;
        int d[m][n];
        
        for (int i = 0; i < m; i++) {
            d[i][0] = i;
        }
        for (int j = 0; j < n; j++) {
            d[0][j] = j;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
             if (word1[i-1] == word2[j-1]) {
                 d[i][j] = d[i-1][j-1];
             } else {
                 d[i][j] = Min(d[i-1][j-1], d[i-1][j], d[i][j-1]) + 1;
             }      
            }
        }
        return d[m-1][n-1];
    }
};