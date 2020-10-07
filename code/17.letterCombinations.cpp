class Solution {
public:
    const vector<string> keyboard { " ", "", "abc", "def", "ghi", "jkl", "mno",
                                        "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {   
        if (digits.empty()) return vector<string>();
        vector<string> result(1, "");
        for (auto d : digits) {
            const size_t n = result.size();
            const size_t m = keyboard[d - '0'].size();

            result.resize(n * m);
            for (size_t i = 0; i < m; ++i) {
                copy(result.begin(), result.begin() + n, result.begin() + n * i);
            }

            for (size_t i = 0; i < m; ++i) {
                auto begin = result.begin();
                for_each(begin + n * i, begin + n * (i+1), [&](string &s) {
                    s += keyboard[d - '0'][i];
                });
            }
     
        }
        return result;
    }
};