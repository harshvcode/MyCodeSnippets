/*
	Program to find distance of all vertices from a particular vertex in
	unweighted acyclic graph
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define vt vector
#define ar array
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(x) (int)(x).size()
#define foor(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define each(x, a) for (auto& x: a)

const int n=8;
vt<int> adj[n];
queue<int> q;
vt<bool> vis(n, false);
vt<int> dist(n, 0);
void bfs(int x){ // Finding distance using bfs
	vis[x]=true;
	q.push(x);
	dist[x]=0;
	while(! q.empty()){
		x=q.front();
		//cout << x << ' ';
		q.pop();
		for(auto u:adj[x]){
			if(vis[u]) continue;
			vis[u]=true;
			dist[u]=dist[x]+1;
			q.push(u);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	adj[0].pb(1);
	adj[0].pb(2);
	adj[0].pb(3);
	adj[1].pb(4);
	adj[7].pb(5);
	adj[2].pb(6);
	adj[3].pb(7);
	bfs(0);
	for(int e:dist) cout << e << '>';
	return 0;
}
