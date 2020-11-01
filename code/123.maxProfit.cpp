class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        int f[n + 1][5 + 1];
        int i, j, k;
        f[0][1] = 0;
        f[0][2] = f[0][3] = f[0][4] = f[0][5] = INT_MIN;

        for (i = 1; i <= n; ++i) {
            // 1, 3, 5
            for (j = 1; j <= 5; j +=2) {
                //max{f[i]-1, f[i-1][j-1] + Pi-1 -P2-2)}
                f[i][j] = f[i - 1][j];
                if (j > 1 && i > 1 && f[i-1][j-1] != INT_MIN) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + prices[i - 1] - prices [i - 2]);
                }
            }

            for (j = 2; j <= 5; j +=2) {
                // max{f[i-1][j] - Pi-1 - Pi-2, f[i-1][j-1], f[i-1][j-2] + Pi-1 - Pi - 2}
                f[i][j] = f[i - 1][j - 1];
                if (i > 1 && f[i-1][j] != INT_MIN) {
                    f[i][j] = max(f[i][j], f[i - 1][j] + prices[i - 1] -prices [i - 2]);
                }

                if (j > 2 && i > 1 && f[i - 1][j - 2] != INT_MIN) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 2] + prices[i - 1] - prices[i - 2]);
                }

            }
        }
        return max(max(f[n][1], f[n][3]), f[n][5]);
    }
};