class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if (set.find(endWord) == set.end()) return 0;
        unordered_set<string> visited;
        unordered_set<string> *beginSet,*endSet,*temp;
        beginSet = new unordered_set<string>; beginSet->insert(beginWord);
        endSet = new unordered_set<string>; endSet->insert(endWord);
        int len = 2;
        while (!beginSet->empty() && !endSet->empty()){
            if (beginSet->size() > endSet->size()){
                temp = beginSet;
                beginSet = endSet;
                endSet = emp;
            }
            temp = new unordered_set<string>;
            for (string word : *beginSet){
                for (int i = 0;i < word.size(); i++){
                    char ch = word[i];
                    for (char c = 'a'; c <= 'z'; c++){
                        if (c == ch) continue;
                        word[i] = c;
                        if(endSet->find(word) != endSet->end()) return len;
                        if(visited.find(word) == visited.end() && set.find(word) != set.end()){
                            visited.insert(word);
                            temp->insert(word);
                        }
                    }
                    word[i] = ch;
                }
            }
            delete beginSet;
            beginSet = temp;
            len++;
        }
        delete beginSet;
        delete endSet;
        return 0;
    }
};