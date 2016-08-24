class Solution {
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> edge(numCourses);
        int len = prerequisites.size();
        vector<int> in(numCourses, 0);
        int u, v;
        queue<int> q;
        for (int i = 0; i < len; i++) {
            v = prerequisites[i].first;
            u = prerequisites[i].second;
            edge[u].push_back(v);
            in[v]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (!in[i])
                q.push(i);
        }
        int ans = 0;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            ans++;
            for (int i = 0; i < edge[u].size(); i++) {
                if (!--in[edge[u][i]]) {
                    q.push(edge[u][i]);
                }
            }
        }
        return ans == numCourses;
    }
};
