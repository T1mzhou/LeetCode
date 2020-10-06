class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        int value = x;
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == value;
    }
};