class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
          int n = prices.size();
        if (n == 0) {
            return 0;
        }

        int i, j, k;
        if (K > n/2) {
            int result = 0;
            for (i = 0; i < n - 1; ++i) {
                result += max(prices[i + 1] - prices[i], 0);
            }
            return result;
        }
        int f[n + 1][2 * K + 1 + 1];
        f[0][1] = 0;
        for (k = 2; k <= 2 * K + 1; ++k) {
            f[0][k] = INT_MIN;
        }
        

        for (i = 1; i <= n; ++i) {
            // 1, 3, 5
            for (j = 1; j <= 2 * K + 1; j +=2) {
                //max{f[i]-1, f[i-1][j-1] + Pi-1 -P2-2)}
                f[i][j] = f[i - 1][j];
                if (j > 1 && i > 1 && f[i-1][j-1] != INT_MIN) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + prices[i - 1] - prices [i - 2]);
                }
            }

            for (j = 2; j <= 2 * K + 1; j +=2) {
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
        int res = INT_MIN;
        for (i = 1; i <= 2 * K + 1; i += 2) {
            res = max(res, f[n][i]);
        }
        return res;
    }
};