class Solution {
public:
    int compareVersion(string version1, string version2) {
        for (int i = 0, j = 0; i < version1.size() || j < version2.size();) {
            int a = i, b = j;
            while (a < version1.size() && version1[a] != '.') a++;
            while (b < version2.size() && version2[b] != '.') b++;
            int x = a == i ? 0 : stoi(version1.substr(i, a - i));
            int y = b == j ? 0 : stoi(version2.substr(j, b - j));
            if (x > y) return 1;
            if (x < y) return -1;
            i = a + 1;
            j = b + 1;
        }
        return 0;
    }
};