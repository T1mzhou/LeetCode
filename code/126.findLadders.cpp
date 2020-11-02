class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;

    queue<string> q;

    unordered_map<string, set<string>> pre; 
    unordered_set<string> vis;
    unordered_set<string> wordSet; 

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        wordSet=unordered_set<string>(wordList.begin(), wordList.end());

        if(wordSet.size() == 0|| wordSet.count(endWord) == 0) return {}; 
        pre[beginWord] = set<string>();
        vis.insert(beginWord);
        q.push(beginWord);

        bool isFound = false;

        while (!q.empty()){
            int qSize = q.size(); 
            unordered_set<string> st;
            for (int k = 0; k < qSize; k++){
                string curWord = q.front(); q.pop();
                int n = curWord.length();
                for (int i = 0;i < n; i++) {
                    for (char ch='a';ch <= 'z'; ch++) {
                        if (curWord[i] != ch) {
                            string newWord = curWord; newWord[i] = ch;
                            if (wordSet.count(newWord) > 0 && vis.count(newWord) == 0){
                                if (newWord==endWord) isFound = true; 

                                if (st.count(newWord) == 0){ ！
                                    st.insert(newWord);
                                    q.push(newWord);
                                }
                                pre[newWord].insert(curWord); 
                            }
                        }
                    }
                }
            }
            if (isFound) break; 
            vis.insert(st.begin(), st.end());
        }
        if (!isFound) return {}; 
        dfs(endWord);
        return res;
    }

    void dfs(string curWord){
        if (pre[curWord].size() == 0){
            path.push_back(curWord);
            vector<string> tmp(path.rbegin(), path.rend());
            res.push_back(tmp);
            path.pop_back();
            return;
        }
        path.push_back(curWord);
        for(set<string>::iterator it= pre[curWord].begin();it!=pre[curWord].end();it++){
            dfs(*it);
        }
        path.pop_back();
    }
};