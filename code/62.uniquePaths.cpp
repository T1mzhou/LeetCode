class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;
        int small = min(m-1, n-1);
        int total = m + n -2;
        long result = 1;
        
        for (int i = 0; i < small; ++i) {
            result = result * (total - i) / (i + 1);
        }
        return result;
    }
};