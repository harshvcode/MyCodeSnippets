#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=4;
vector<int> adj[N];
queue<int> q;
bool visited[N];
int distance[N];
void bfs(int s){
	visited[s]=true;
	q.push(s);
	while(!q.empty()){
		s=q.front();
		cout << s << '>';
		q.pop();
		for(auto u:adj[s]){
			if(visited[u]) continue;
			visited[u]=true;
			q.push(u);
		}
	}
}
void dfs(int s){
	if(visited[s]) return;
	visited[s]=true;
	cout << s << '>';
	for(auto u:adj[s])
		dfs(u);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	adj[0].pb(1);
	adj[0].pb(2);
	adj[1].pb(2);
	adj[2].pb(0);
	adj[2].pb(3);
	adj[3].pb(3);
	bfs(2);
	return 0;
}
