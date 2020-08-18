/*****Author  : harshvcode*****/
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
const int n=9;//Bcoz vertex number ranges from 1 to 8 in specified input in main()
VT<int> adj[n];
stack<int> stac;
VT<bool> vis(n, 0);
// Following topSorter function is dfs with little modification
void topSorter(int v){
	if(vis[v]) return;
	vis[v]=1;
	for(auto e:adj[v]){
		if(vis[e]) continue;
		topSorter(e);
	}
	stac.push(v);
}
void topSort(){
	FR(i, 1, n, 1)
		if(! vis[i])
			topSorter(i);
	//Now All the elements are int stac after sorting, So now just pop and print
	while(! stac.empty())
		cout << stac.top() << " -> ",
		stac.pop();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	adj[1].PB(3);
	adj[2].PB(3);
	adj[3].PB(5);
	adj[2].PB(4);
	adj[5].PB(6);
	adj[4].PB(6);//See what happens by changing this line to adj[6].PB(4) or changing Line No. 37 to FR(i, 8, 0, -1)
	adj[6].PB(7);
	adj[6].PB(8);
	topSort();
	return 0;
}
