#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define VT vector
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define SZ(x) (int)(x).size()
#define FR(i, a, b, s) for (auto i=(a); (s)>0?i<=(b):i>=(b); i+=(s))
#define ECH(x, a) for (auto& x: a)
#define F first
#define S second
#define MP make_pair
#define int long long
#define PII pair<int,int>
#define MII map<int,int>
#define PQB priority_queue<int>
#define PQS priority_queue<int,vi,greater<int>>
#define SB(x) __builtin_popcountll(x)
#define ZB(x) __builtin_ctzll(x)
#define MOD 1000000007
#define INF 1e18
#define MK(arr,n,type)  type *arr=new type[n];
#define SPLT(x, y, z) for(auto x=strtok(&y[0], z);x!=NULL;x=strtok(NULL,z))
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
int randnum(int a, int b) {
	return uniform_int_distribution<int>(a, b)(mt_rng);
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
void pre(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
}
int bellmanFord(VT<PII> adj[], VT<int>& dist, int& n, int& from){
	dist[from] = 0;
    for(int i = 0; i <= n; i++){
        // traverse all the edgess n times and even if the nth time the distance reduces it means there is a negative edges.
        for(int j = 0;j < adj[i].size(); j++){
        	int u = i;
        	int v = adj[i][j].F;
        	int wt = adj[i][j].S;
        	if(dist[v] > dist[u]+wt){
        		if(i == n){
                    // if the reduction happens even on the nth iteration, then there is a negative cycle present.
                    // because each shortest path can contain atmost (n-1) edges.
        			return -1;
        		}
        		dist[v] = dist[u]+wt;
        	}
        }
    }
    return 0;
}
int32_t main(){
	pre();
	int n;
	cin >> n;
	VT<PII> adj[n+1];
	VT<int> dist(n+1, INF);
	FR(i, 1, n, 1){
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].PB(MP(v, wt));
	}
	int from;//from which vertex to find minimum cost path
	cin >> from;
	bellmanFord(adj, dist, n, from);
	FR(i, 1, n, 1)
		cout << "Min. distance from " << from,
		cout <<" to " << i << " : " << dist[i] << '\n';
	return 0;
}
