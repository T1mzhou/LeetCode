class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& str: strs) {
            string backup = str;
            sort(backup.begin(), backup.end());
            hash[backup].push_back(str);
        }        

        vector<vector<string>> res;
        for (auto& item : hash) res.push_back(item.second);

        return res;
    }
};