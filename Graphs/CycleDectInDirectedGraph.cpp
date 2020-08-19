/*
  Author  : harshvcode
  BFS & DFS & Cycle detection in directed graph
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
template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1; 
	} 
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		f(mb)?lb=mb:rb=mb-1; 
	} 
	return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	each(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	each(a, x)
		read(a);
}
template<class T> void offset(ll o, T& x) {
	x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
	each(a, x)
		offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	each(a, x)
		offset(o, a);
}
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
	v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
	v=vt<T>(n);
	each(a, v)
		vti(a, x, m);
}
void to_string(bool val){
	if(val)
		cout << "true\n";
	else
		cout << "false\n";
}
const int n=4;
vt<int> adj[n];
bool visited[n];
bool recstack[n];
queue<int> q;
void bfs(int x){
	visited[x]=true;
	q.push(x);
	while(! q.empty()){
		x=q.front();
		cout << x << ' ';
		q.pop();
		for(auto u:adj[x]){
			if(visited[u]) continue;
			visited[u]=true;
			q.push(u);
		}
	}
}
void dfs(int x){
	if(visited[x]) return;
	visited[x]=true;
	cout << x << ' ';
	for(auto u:adj[x])
		dfs(u);
}
bool iscyclic(int x){
	visited[x]=true;
	recstack[x]=true;
	for(auto vert:adj[x]){
		if(visited[vert] == false && recstack[vert] == false)
			return iscyclic(vert);
		else if(recstack[vert] == true)
			return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	adj[0].pb(1);
	adj[0].pb(2);
	adj[1].pb(2);
	adj[2].pb(3);
	//adj[2].pb(3);
	adj[3].pb(1);
	to_string(iscyclic(0));
	return 0;
}
