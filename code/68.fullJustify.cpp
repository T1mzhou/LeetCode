class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            int j = i + 1;
            int len = words[i].size();
            while (j < words.size() && len + 1 + words[j].size() <= maxWidth) {
                len += 1 + words[j++].size();
            }

            string line;
            if (j == words.size() || j == i + 1) {
                line += words[i];
                for (int k = i + 1; k < j; k++) {
                    line += ' ' + words[k];
                }
                while (line.size() < maxWidth) line += ' '; 
            } else {
                int cnt = j - i - 1, r = maxWidth - len + cnt;
                line += words[i];
                int k = 0;
                while (k < r % cnt) line += string(r / cnt + 1, ' ') + words[i + k + 1], k++;
                while (k < cnt) line += string(r / cnt, ' ') + words[i + k + 1], k++;
            }
            res.push_back(line);
            i = j - 1;
        }
        return res;
    }
};