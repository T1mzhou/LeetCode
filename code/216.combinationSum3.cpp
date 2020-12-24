class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, n, k);
        return ans;
    }

    void dfs(int start, int n, int k) {
        if (!n) {
            if (!k) ans.push_back(path);
        } else if (k) {
            for (int i = start; i <= 9; i++) {
                path.push_back(i);
                dfs(i + 1, n - i, k - 1);
                path.pop_back();
            }
        }

    }
};