/*****Author	:	harshvcode*****/
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
#define FR(i, a, b, s) for (int i=(a); (s)>0?i<=(b):i>=(b); i+=(s))
#define ECH(x, a) for (auto& x: a)
#define F first
#define S second
#define MP make_pair
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randnum(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}
template<class T>
string tostr(T v){
	if(v) return "true";
	return "false";
}
string seqstr(VT<int>& arr, const string& delim){
	string p="";
	ECH(x, arr) p+=to_string(x)+delim;
	return p.substr(0, p.size()-1);
}

#define INF 999999999999
ll n, m;
//set distance below as per max size of graph possibly 1000009
ll dist[10], par[1000009];
void dijkstras(VT<pair<ll, ll>> graph[]){
	ll i;
	set<pair<ll, ll>> st;
	st.insert(MP(0, 1));//From 1 whose self distance is 0. So (0(self distance), 1(from vertex)) initially in set
	for(i=1; i<=n; i++)
		dist[i]=INF;
	dist[1]=0;
	par[1]=0;
	while(! st.empty()){
		set<pair<ll, ll>>::iterator it=st.begin();
		ll u=it->S;
		st.erase(st.begin());
		for(i=0; i<graph[u].size(); i++){
			ll wt=graph[u][i].F;
			ll v=graph[u][i].S;
			if(dist[v] > dist[u]+wt){
				if(dist[v] != INF){
					st.erase(st.find(MP(dist[v], v)));
				}
				dist[v]=dist[u]+wt;
				st.insert(MP(dist[v], v));
				par[v]=u;
			}
		}
	}
}
int getMinDist(VT<pair<ll, ll>> graph[]){
	dijkstras(graph);//Calling dijkstras to fill dist vector with min. distances
	ll fromVert;
	printf("Enter vertex which to find min. dis. from: ");
	cin >> fromVert;//Takes from which node you want to calculate min. dist;
	printf("Enter vertex you want min. distance to: ");
	ll ofWhichVertex;//Of which vertex you want min. distance to?
	cin >> ofWhichVertex;
	if(dist[fromVert] == INF || dist[ofWhichVertex] == INF)// If vertex is not reachable
		return -1;//If can't be reached
	return abs(dist[fromVert] - dist[ofWhichVertex]);
}
/*Sample Input
6
8
1 2 2
1 3 4
2 4 7
2 3 1
3 5 3
4 6 1
4 5 2
5 6 5
*/
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	VT<pair<ll, ll>> graph[n+1];
	ll i;
	for(i=0; i<m; i++){
		ll a, b, wt;
		cin >> a >> b >> wt;
		graph[a].PB(MP(wt, b));
		graph[b].PB(MP(wt, a));//Remove this line in case of directed Graph
	}
	cout << getMinDist(graph);
	return 0;
}
