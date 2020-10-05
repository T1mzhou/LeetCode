class Solution {
public:
    int myAtoi(string str) {
        int k = 0;
        while (k < str.size() && str[k] == ' ') k++;
        if (k == str.size()) return 0;

        int flag = 1;
        if (str[k] == '-') flag = -1, k++;
        else if (str[k] == '+') k++;

        int res = 0;
        while (k < str.size() && str[k] >= '0' && str[k] <= '9') {
            int x = str[k] - '0';
            if (flag > 0 && res > (INT_MAX - x) / 10) return INT_MAX;
            if (flag < 0 && -res < (INT_MIN + x) / 10) return INT_MIN;
            if (-res * 10 - x == INT_MIN) return INT_MIN;
            res = res * 10 + x;
            k++;
            if (res > INT_MAX) break;
        }

        res *= flag;
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;

        return res;
    }
};