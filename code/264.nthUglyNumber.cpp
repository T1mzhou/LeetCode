class Solution {
public:
    int Min(int a, int b, int c) {
        return min(a, min(b, c));
    }
    
    int nthUglyNumber(int n) {
        if (n <= 0) return -1;
        int uglyNums[n];
        uglyNums[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        
        for (int i = 1; i < n; ++i) {
            int minNums = Min(uglyNums[p2]*2, uglyNums[p3]*3, uglyNums[p5]*5);
            uglyNums[i] = minNums;
            if (minNums == uglyNums[p2]*2) ++p2;
            if (minNums == uglyNums[p3]*3) ++p3;
            if (minNums == uglyNums[p5]*5) ++p5;
        }
        return uglyNums[n-1];
    }
};