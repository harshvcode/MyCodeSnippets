*************Graph Data Structure***************************
#include<bits/stdc++.h>
using namespace std;
int INF=1e5+5;
struct Graph{
  int V;
  vector<vector<pair<int, int>>> G;
  vector<short> VIS;
  void init(int v){
    V=v;
    G.resize(V);
    VIS.resize(V);
  }
  void add(int u, int v, int w = -1){
  	assert(u >= 0 && v >= 0);//ensures +ve vertices
  	G[u].push_back({v,w});
  	//G[v].push_back({u,w});//comment if directed
  }
  void dfs(int v){
  	if(VIS[v]) return;
  	cout << v << " ";
  	VIS[v] = 1;
  	for(auto e : G[v])
  	{
  		if(! VIS[e.first])
  		{
  			dfs(e.first);
  		}
  	}
  }
  void bfs(int v){
  	queue<int> q;
  	q.push(v);
  	VIS[v] = 1;
  	while(! q.empty())
  	{
  		v = q.front();
  		q.pop();
  		cout << v << " ";
  		for(auto e : G[v])
  		{
   			if(! VIS[e.first])
  			{
  				q.push(e.first);
  				VIS[e.first] = 1;
  			}
  		}
  	}
  }
  void resetVis(bool c){//arg is for newline
  	if(c) cout << "\n";
  	fill(VIS.begin(), VIS.begin()+V, 0);
  }
  void utiltopSort(int v, stack<int>& st){
  	if(VIS[v]) return;
  	VIS[v] = 1;
  	for(auto e : G[v])
  	{
  		utiltopSort(e.first, st);
  	}
  	st.push(v);
  }
  void topSort(){
  	stack<int> st;
  	for(int i = 0; i < V; ++i)
  		if(! VIS[i])
  			utiltopSort(i, st);
  	while(! st.empty()) { cout << st.top() << " "; st.pop(); }
  	cout << "\n";
  }
  bool utilcycDir(int v){
  	if(VIS[v] == 1) return 1;
  	if(VIS[v] == 2) return 0;
  	VIS[v] = 1;
  	for(auto e:G[v]){
  		if(utilcycDir(e.first)) return 1;
  	}
  	VIS[v] = 2;
  	return 0;
  }
  bool cycDir(){
  	for(int i=0; i<V; ++i){
  		if(! VIS[i] && utilcycDir(i))
  			return 1;
  	}
  	return 0;
  }
  void priMst(){
  	int src=0;
  	vector<int> dist(V,INF);
  	vector<int> par(V,-1);
  	//VIS will be used to check whether a vertex is in MST.
  	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//weight, vertex
  	pq.push({0,src});
  	VIS[src]=1;
  	dist[src]=0;
  	while(! pq.empty())
  	{
  		int u=pq.top().second;
  		pq.pop();
  		VIS[u]=1;
  		for(auto e:G[u]){
  			int v=e.first;
  			int w=e.second;
  			if(! VIS[v] && dist[v] > w){
  				dist[v]=w;
  				pq.push({dist[v],v});
  				par[v]=u;
  			}
  		}
  	}
  	for(int i=0; i<V; ++i) cout<<par[i]<<"->"<<i<<"\n";
  }
  void dijkstras(int s){//arg is src
  	vector<int> d (V, INF), p(V);
  	d[s] = 0;
  	for (int i=0; i<V; ++i) {
  		int v = -1;
  		for(int j=0; j<V; ++j)
  			if (!VIS[j] && (v == -1 || d[j] < d[v]))
  				v = j;
  		if (d[v] == INF)
  			break;
  		VIS[v] = 1;

  		for (size_t j=0; j<G[v].size(); ++j) {
  			int to = G[v][j].first;
  				int len = G[v][j].second;
  			if (d[v] + len < d[to]) {
  				d[to] = d[v] + len;
  				p[to] = v;
  			}
  		}
  	}
  	for(int i=0; i<V; ++i) cout<<i<<"->"<<d[i]<<"\n";
  }
  void bellmanFord(int src){
    vector<int> dist(V, INF);
    dist[src]=0;
    for(int u=0; u<V; ++u){
      for(auto e:G[u]){
        int v=e.first;
        int w=e.second;
        int tmpDist=dist[u]+w;
        if(tmpDist < dist[v]){
          dist[v]=tmpDist;
        }
      }
    }
    dist[src]=0;
    for(int i=0; i<V; ++i) cout<<i<<"->"<<dist[i]<<"\n";
  }
};
int main(){
  Graph g;
  int V;//size of Graph
  cin >> V;
  g.init(V);
  int n;//no. of edges
  cin >> n;
  for(int i=0; i<n; ++i){
    int u, v;
    cin>>u>>v;
    g.add(u, v);
  }
  cout << g.cycDir();
  return 0;
}
