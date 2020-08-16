/*
	detect cycle in directed graph using only one boolean vector 'vis', while in previous code i used recstack named additional vector
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

const int n=5;
vt<int> adj[n];
queue<int> q;
vt<bool> vis(n, 0);
bool iscyclic(int v){
	vis[v]=1;
	for(auto vert:adj[v]){
		if(vis[vert]) return true;
		else return iscyclic(vert);
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	adj[0].pb(1);
	adj[1].pb(4);
	adj[2].pb(0);
	adj[2].pb(4);//to check change this line with adj[2].pb(4) to adj[4].pb(2)
	adj[3].pb(0);
	cout << iscyclic(3);
	return 0;
}
