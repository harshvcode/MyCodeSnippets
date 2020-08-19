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
const int n=7;
VT<int> adj[n];
// Below function is BFS with little modification
bool findMother(int v){
	VT<bool> reachable(n, false);
	queue<int> que;
	reachable[v]=1;
	que.push(v);
	while(! que.empty()){
		v=que.front();
		que.pop();
		for(auto e:adj[v]){
			if(reachable[e]) continue;
			reachable[e]=true;
			que.push(e);
		}
	}
	// Below loop to check whether all vertex has been visited(reachable) or not.
	for(bool e:reachable)
		if(e == false) return false;
	return true;
}
int motherVertex(){
	FR(i, 0, n, 1)
		if(findMother(i))
			return i;
	return -1; // If there is no mother vertex present
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
