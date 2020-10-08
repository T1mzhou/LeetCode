class Solution {
public:
    void generate(vector<string>& result, string str, int left, int right)
    {
        if (left == 0 && right == 0) {
            result.push_back(str);
            return;
        } else {
            if (left > 0) generate(result, str + '(', left - 1, right);
            if (right > left) generate(result, str + ')', left, right - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str;
        if (n < 0) return result;
        generate(result, "", n, n);
        return result;
    }
};
