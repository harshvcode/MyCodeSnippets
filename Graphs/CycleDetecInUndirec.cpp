/*
  By  : harshvcode
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define VT vector
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define SZ(x) (int)(x).size()
#define FR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define ECH(x, a) for (auto& x: a)
#define F first
#define S second
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randnum(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}
const int n=4;
VT<int> adj[n];
queue<int> q;
VT<bool> vis(n, 0);
void dfs(int v){
	if(vis[v]) return;
	cout << v << ' ';
	vis[v]=true;
	for(auto e:adj[v])
		dfs(e);
}
void bfs(int v){
	vis[v]=true;
	q.push(v);
	while(! q.empty()){
		v=q.front();
		cout << v << ' ';
		q.pop();
		for(auto e:adj[v]){
			if(vis[e]) continue;
			vis[e]=1;
			q.push(e);
		}
	}
}
void add(int v1, int v2){
	adj[v1].PB(v2);
	adj[v2].PB(v1);
}
//Detect cycle in undirected graph, But any vertex must not be -1
//as i have used parent value default as -1,
//Other wise we have to use a bool value for first time recursion call
bool detecCycleInUnd(int v, int parent=-1){
	if(v != parent && vis[v]) return 1;
	vis[v]=1;
	for(auto e:adj[v]){
		if(e != parent){
			if(vis[e]) return 1;
			else return detecCycleInUnd(e, v);
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	add(0, 1);
	add(2, 0);
	add(1, 3);
	//add(3, 2); This line makes cycle, see what happens by commenting and uncommenting this line.
	cout << detecCycleInUnd(0);
	return 0;
}
