/*****Authored by harshvcode*****/
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
const int n=7;
VT<int> adj[n];
VT<bool> vis(n ,0);
//	Using DFS to find Mother Vertex
void dfs(int v){
	if(vis[v]) return;
	vis[v]=1;
	for(auto e:adj[v]){
		if(vis[e]) continue;
		dfs(e);
	}
}
int motherVertex(){
	int Mother=-1;
	FR(i, 0, n, 1)
		if(! vis[i]){
			dfs(i);
			Mother=i;
		}
	fill(ALL(vis), false);
	dfs(Mother);
	for(bool visited:vis)
		if(! visited) return -1;//If there is not any mother vertex
	return Mother;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	adj[0].PB(1);
	adj[0].PB(2);
	adj[1].PB(3);
	adj[4].PB(1);
	adj[5].PB(2);
	//adj[5].PB(6); //See what happens by commenting and uncommenting this line
	adj[6].PB(0);
	adj[6].PB(4);
	cout << motherVertex();
	return 0;
}
