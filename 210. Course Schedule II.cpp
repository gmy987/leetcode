class Solution {
  public:
    vector<int> findOrder(int numCourses,
                          vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> in(numCourses, 0);
        int len = prerequisites.size();
        int u, v;
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            u = prerequisites[i].second;
            v = prerequisites[i].first;
            in[v]++;
            edge[u].push_back(v);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!in[i])
                q.push(i);
        }
        while (!q.empty()) {
            u = q.front();
            q.pop();
            ans.push_back(u);
            for (int i = 0; i < edge[u].size(); i++) {
                v = edge[u][i];
                if (!--in[v]) {
                    q.push(v);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};
