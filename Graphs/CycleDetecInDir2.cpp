#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define int long long
#define f(i,a,b,o) for(auto i=a;(o>0)?i<=b:i>=b;i+=o)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x) int x; cin>>x; while(x--)
#define full(x) (x).begin(),(x).end()
#define nl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void pre(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
}

vi adj[8];
vector<bool> vis(8, 0);
vector<int> color(8, 0);//white
bool cyc=0;
void cycleDir(int v){
	if(vis[v]) return;
	vis[v]=1;
	color[v]=1;
	for(int e:adj[v]){
		if(color[e] == 0) cycleDir(e);
		else if(color[e] == 1){ cyc=1; return; }
	}
	color[v]=2;
}
void add(int a, int b){
	adj[a].pb(b);
}
int32_t main()
{
	pre();
	add(0, 1);
	add(0, 2);
	add(0, 3);
	add(1, 4);
	add(1, 5);
	add(5, 6);
	add(6, 7);
	add(7, 2);
	cycleDir(0);
	cout << cyc;
	return 0;
}
