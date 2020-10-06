class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if (numRows == 1) return s;
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.size(); j += 2 * numRows - 2) {
                    res += s[j];
                }
            } else {
                for (int j = i, k = 2 * numRows - 2 -i; j < s.size() || k < s.size() ||
                    k < s.size(); j += 2 * numRows - 2, k += 2 * numRows - 2) {
                        if (j < s.size()) res += s[j];
                        if (k < s.size()) res += s[k];
                }
            } 
        }
        return res;
    }
};