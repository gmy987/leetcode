#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Hello World";
    return 0;
}

// QuickSort
void quickSort(vector<int> &nums, int low, int high) {
    if (low < high) {
        int i = low, j = high, p = nums[low];
        while (i < j) {
            while (i < j && nums[j] >= p)
                j--;
            nums[i] = nums[j];
            while (i < j && nums[i] <= p)
                i++;
            nums[j] = nums[i];
        }
        nums[i] = p;
        quickSort(nums, low, i - 1);
        quickSort(nums, i + 1, high);
    }
}

//*********************************************************************
// 最短路
struct Edge {
    int v, next, w;
} edge[maxm];

void addedge(int u, int v, int w) {
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}

// Dijkstra
void Dijkstra(int t, int n) {
    int k;
    bool vis[MAXN];
    int h[MAXN];
    memset(vis, 0, sizeof(vis));
    memset(h, 0x7f, sizeof(h));
    h[t] = 0;
    for (int i = 1; i <= n; i++) {
        k = 0;
        for (i = 1; i <= n; i++) {
            if (!vis[i] && (!k || h[i] < h[k]))
                k = i;
        }
        vis[k] = 1;
        for (i = head[k]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            h[v] = min(h[v], h[k] + edge[i].w);
        }
    }
}
// Dijkstra heap
struct cmp {
    bool operator()(int a, int b) { return h[a] > h[b]; }
};
void Dijkstra(int t, int n) {
    priority_queue<int, vector<int>, cmp> q;
    memset(h, 0x7f, sizeof(h));
    memset(vis, 0, sizeof(vis));
    h[t] = 0;
    q.push(t);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].w;
            if (h[v] > h[u] + w) {
                h[v] = h[u] + w;
                q.push(v);
            }
        }
    }
}

// SPFA
void spfa(int t) {
    memset(vis, 0, sizeof(vis));
    memset(h, 0x7f, sizeof(h));
    queue<int> q;
    h[t] = 0;
    q.push(t);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].v, w = edge[i].w;
            if (h[u] + w < h[v]) {
                h[v] = h[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

//*********************************************************************
// 最小生成树
// Prim算法
int prim() {
    int i, j, pos, min, result = 0;
    memset(vis, 0, sizeof(vis));
    vis[1] = 1, pos = 1;
    for (i = 1; i <= n; i++) {
        if (i != pos)
            low[i] = map[pos][i];
    }
    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 1; j <= n; j++) {
            if (!vis[j] && min > low[j]) {
                min = low[j];
                pos = j;
            }
        }
        result += min;
        vis[pos] = 1;
        for (j = 1; j <= n; j++) {
            if (!vis[j] && low[j] > map[pos][j])
                low[j] = map[pos][j];
        }
        return result;
    }
}
