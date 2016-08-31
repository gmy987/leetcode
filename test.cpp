#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Hello World";
    return 0;
}

void quickSort(int low, int high, vector<int> &nums) {
    if (low < high) {
        int i = low, j = high, p = nums[i];
        while (i < j) {
            while (i < j && nums[j] >= p)
                j--;
            nums[i] = nums[j];
            while (i < j && nums[i] <= p)
                i++;
            nums[j] = nums[i];
        }
        nums[i] = p;
        quickSort(low, i - 1, nums);
        quickSort(i + 1, high, nums);
    }
}

void merge_(int l, int mid, int r, vector<int> &nums) {
    int i1 = l, i2 = mid, i3 = 0;
    vector<int> tmp(r - l + 1);
    while (i1 <= mid && i2 <= r) {
        if (nums[i2] > nums[i1])
            tmp[i3++] = nums[i1++];
        else
            tmp[i3++] = nums[i2++];
    }
    while (i1 <= mid)
        tmp[i3++] = nums[i1++];
    while (i2 <= r)
        tmp[i3++] = nums[i2++];
    for (int i = 0, j = l; i < i3; i++, j++)
        nums[j] = tmp[i];
}

void mergeSort(int l, int r, vector<int> &nums) {
    if (l + 1 > r)
        return;
    int mid = l + r >> 1;
    mergeSort(l, mid, nums);
    mergeSort(mid + 1, r, nums);
    merge_(l, mid, r, nums);
}

struct Edge {
    int to, next, w;
} edge[maxm];

void Dijkstra(int t, int n) {
    memset(vis, 0, sizeof(vis));
    memset(h, 0x7f, sizeof(h));
    h[t] = 0;
    int k;
    for (int i = 1; i <= n; i++) {
        k = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && (!k || h[i] < h[k]))
                k = i;
        }
        vis[k] = 1;
        for (int i = head[k]; ~i; i = edge[i].next) {
            int v = edge[i].to, w = edge[i].w;
            h[v] = min(h[v], h[k] + w);
        }
    }
}

struct cmp {
    bool operator()(int a, int b) { return h[a] > h[b]; }
};

bool Dijkstra(int t, int n) {
    priority_queue<int, vector<int>, cmp> q;
    q.push(t);
    memset(vis, 0, sizeof(vis));
    memset(h, 0x7f, sizeof(h));
    h[t] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to, w = edge[i].w;
            if (h[v] > h[u] + w) {
                h[v] = h[u] + w;
                q.push(v);
            }
        }
    }
}

void spfa(int t) {
    memset(vis, 0, sizeof(vis));
    memset(h, 0x7f, sizeof(h));
    h[t] = 0;
    queue<int> q;
    q.push(t);
    vis[t] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to, w = edge[i].w;
            if (h[v] > h[u] + w) {
                h[v] = h[u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
