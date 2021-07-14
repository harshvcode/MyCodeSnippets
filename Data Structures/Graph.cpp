#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;
ll inf = 1ll << 60;
int mod = 1e9 + 7;
#define mem(dp,a) memset(dp,a,sizeof dp)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define pb(x) push_back(x)

int V;
vector<vector<pair<int, int>>> gr;
vector<short> vis;
void grinit(int N) {
    gr.resize(N);
    vis.resize(N);
    V = N;
}
void add(int u, int v, int w = -1) {
    assert(u >= 0 && v >= 0);//ensures +ve vertices
    gr[u].push_back({v, w});
    //gr[v].push_back({u,w});//comment if directed
}
void dfs(int v) {
    if (vis[v]) return;
    cout << v << " ";
    vis[v] = 1;
    for (auto e : gr[v])
    {
        if (! vis[e.first])
        {
            dfs(e.first);
        }
    }
}
void bfs(int v) {
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    while (! q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << " ";
        for (auto e : gr[v])
        {
            if (! vis[e.first])
            {
                q.push(e.first);
                vis[e.first] = 1;
            }
        }
    }
}
void resetVis(bool c) { //arg is for newline
    if (c) cout << "\n";
    fill(vis.begin(), vis.begin() + V, 0);
}
void utiltopSort(int v, stack<int>& st) {
    if (vis[v]) return;
    vis[v] = 1;
    for (auto e : gr[v])
    {
        utiltopSort(e.first, st);
    }
    st.push(v);
}
void topSort() {
    stack<int> st;
    for (int i = 0; i < V; ++i)
        if (! vis[i])
            utiltopSort(i, st);
    while (! st.empty()) { cout << st.top() << " "; st.pop(); }
    cout << "\n";
}
bool utilcycDir(int v) {
    if (vis[v] == 1) return 1;
    if (vis[v] == 2) return 0;
    vis[v] = 1;
    for (auto e : gr[v]) {
        if (utilcycDir(e.first)) return 1;
    }
    vis[v] = 2;
    return 0;
}
bool cycDir() {
    for (int i = 0; i < V; ++i) {
        if (! vis[i] && utilcycDir(i))
            return 1;
    }
    return 0;
}
void priMst() {
    int src = 1;
    vector<int> dist(V, inf);
    vector<int> par(V, -1);
    //VIS will be used to check whether a vertex is in MST.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //weight, vertex
    pq.push({0, src});
    vis[src] = 1;
    dist[src] = 0;
    while (! pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        vis[u] = 1;
        for (auto e : gr[u]) {
            int v = e.first;
            int w = e.second;
            if (! vis[v] && dist[v] > w) {
                dist[v] = w;
                pq.push({dist[v], v});
                par[v] = u;
            }
        }
    }
    for (int i = 0; i < V; ++i) cout << par[i] << "->" << i << "\n";
}
void dijkstras(int s) { //arg is src
    vector<int> d (V, inf), p(V);
    d[s] = 0;
    for (int i = 0; i < V; ++i) {
        int v = -1;
        for (int j = 0; j < V; ++j)
            if (!vis[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == inf)
            break;
        vis[v] = 1;

        for (size_t j = 0; j < gr[v].size(); ++j) {
            int to = gr[v][j].first;
            int len = gr[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    for (int i = 0; i < V; ++i) cout << i << "->" << d[i] << "\n";
}
void bellmanFord(int src) {
    vector<int> dist(V, inf);
    dist[src] = 0;
    for (int u = 0; u < V; ++u) {
        for (auto e : gr[u]) {
            int v = e.first;
            int w = e.second;
            int tmpDist = dist[u] + w;
            if (tmpDist < dist[v]) {
                dist[v] = tmpDist;
            }
        }
    }
    dist[src] = 0;
    for (int i = 0; i < V; ++i) cout << i << "->" << dist[i] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    grinit(6);//init graph size
    f(5)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    return 0;
}
