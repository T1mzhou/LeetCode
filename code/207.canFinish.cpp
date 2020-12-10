class Solution {
public:
    //  有向图求拓扑排序
    // 1.统计所有点的入度
    // 2.将入度为0的点入队
    // 3.BFS
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> d(numCourses);
        for (auto& e: prerequisites) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            d[b]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (d[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt++;
            for (auto i : g[t]) {
                if (--d[i] == 0) {
                    q.push(i);
                }
            }
        }
        return cnt == numCourses;
    }
};