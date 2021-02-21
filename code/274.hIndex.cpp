class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0; 
        sort(citations.begin(), citations.end(), greater<int>());

        for (int h = citations.size(); h; h--) {
            if (citations[h - 1] >= h) return h;
        }
        return 0;
    }
};