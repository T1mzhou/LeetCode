class WordDictionary {
public:
    struct Node
    {
        bool is_end;
        Node *next[26];
        Node()
        {
            is_end = false;
            for (int i = 0; i < 26; i ++ )
                next[i] = 0;
        }
    }*root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *p = root;
        for (auto c : word) {
            int u = c - 'a';
            if (!p->next[u]) p->next[u] = new Node();
            p = p->next[u];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(Node* p, string& word, int i) {
        if (i == word.size()) {
            return p->is_end;
        }
        if (word[i] != '.') {
            int u = word[i] - 'a';
            if (!p->next[u]) return false;
            return dfs(p->next[u], word, i + 1);
        } else {
            for (int j = 0; j < 26; j++) {
                if (p->next[j] && dfs(p->next[j], word, i + 1)) 
                    return true;
            }
            return false;
        }
   }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */