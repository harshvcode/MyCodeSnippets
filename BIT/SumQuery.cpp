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
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randnum(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}
template<class T>
string tostr(T v){
	if(v) return "true";
	return "false";
}
//Binary index tree to keep track of sums cumulative
VT<int> BIT(10, 0);
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	VT<int> arr{1,2,3,4,5,6,7,8,9,10};
	int sm=0;
	FR(i, 0, 9, 1){
		sm+=arr[i];
		BIT[i]+=sm;
	}
	int start, end;//From which index to which index you want addition of ?
	cin >> start >> end;
	cout << "Sum in between start range to end: " << ( BIT[end] -BIT[start-1] );
	return 0;
}
