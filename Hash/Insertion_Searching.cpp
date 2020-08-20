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
#define FR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define ECH(x, a) for (auto& x: a)
#define F first
#define S second
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randnum(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}
template<class T>
string tostr(T v){
	if(v) return "true";
	return "false";
}

const int MaxLimit=1000; // Bcoz element to be inserted are <=1000.
bool has[MaxLimit + 1][2];
bool _search(int v){
	if(v > MaxLimit) return false;
	if(v >= 0){//if no. is positive
		if(has[v][0]) return true;
		return false;//If not found
	}
	//If no. is negative
	v=abs(v);
	if(has[v][1]) return true;
	return false;//If not found
}
void insert(){//For taking input and insert into hashtable
	int n=0, el=0;//How many no. to take input
	cin >> n;
	while(n--){
		cin >> el;
		if(el > MaxLimit){
			cout << "Hey Array is OUT OF LIMIT\n";
			return;
		}
		if(el >= 0)
			has[el][0]=1;
		else has[abs(el)][1]=1;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	insert();
	cout << tostr(_search(1000));
	return 0;
}
