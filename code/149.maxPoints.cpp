class Solution {
public:
    string computeKey(int x, int y) {
        int cd = computeCommonDivisor(x, y);
        return to_string(x / cd) + "_" + to_string(y / cd);
    }

    int computeCommonDivisor(int x, int y) {
        if (y == 0)
            return x;
        int z = x % y;
        return computeCommonDivisor(y, z);
    }

    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3)
            return points.size();

        int maxCount = 1;
        unordered_map<string, int> lineMap;

        for (int i = 0; i < points.size() - 1; i++)
        {
            lineMap.clear();
            int horLines = 1;
            int verLines = 1;
            int count = 1;
            int duplicates = 0;

            for (int j = i + 1; j < points.size(); j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if ((x1 == x2) && (y1 == y2)) {
                    duplicates++;
                }
                else if (x1 == x2) {
                    verLines++;
                    count = max(verLines, count);
                }
                else if (y1 == y2) {
                    horLines++;
                    count = max(horLines, count);
                }
                else {
                    string key = computeKey(x1 - x2, y1 - y2);
                    lineMap[key]++;
                    count = max(lineMap[key] + 1, count);
                }
            }
            
            maxCount = max(count + duplicates, maxCount);
        }
        
        return maxCount;
    }
};