class Solution {
public:
    bool isValidTwoDigit(char a, char b) {
        return (a == '1' && b <= '9') || (a == '2' && b <= '6');
    }
    
    int numDecodings(string s) {
        int first = 1;
        int second = s[0] != '0' ? 1 : 0;
        for (int i = 2; i <= s.size(); ++i) {
            int third = 0;
            if (s[i-1] != '0') third += second;
            if (isValidTwoDigit(s[i-2], s[i-1])) third += first;
            first = second;
            second = third;
        }
        return second;
    }
};