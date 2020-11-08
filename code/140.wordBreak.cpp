class Solution {
public:
    vector<bool> f;
    unordered_set<string> hash;
    vector<string> ans;
    int n;
    void dfs(string &s, int u, string now) {
        if(u == s.size()){
            now.pop_back();
            ans.push_back(now);
            return;
        }
        for(int j = u; j < n; j++){
            if(hash.count(s.substr(u,j-u+1))&&f[j+1]) dfs(s,j+1,now+s.substr(u,j-u+1)+" ");
        }
    } 
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size(), f.resize(n+1);
        for(auto w : wordDict) hash.insert(w);
        f[n] = true;
        for(int i = n-1; ~i; i--){
            for(int j = i; j < n; j++){
                if(hash.count(s.substr(i,j-i+1))&&f[j+1]){
                    f[i] = true;
                    break;
                } 
            }
        }
        dfs(s,0,"");
        return ans;
    }
};