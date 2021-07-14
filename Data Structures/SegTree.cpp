#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;
ll inf = 1ll << 60;
int mod = 1e9 + 7;
#define mem(dp,a) memset(dp,a,sizeof dp)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define pb(x) push_back(x)

int N;
vector<int> arr;
vector<int> ST;
void segtreeinit(int n) {
    N = n;
    arr.resize(N); ST.resize(N * 4);
}
void build(int ind, int low, int high) {
    if (low == high) {
        ST[ind] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    ST[ind] = max(ST[2 * ind + 1], ST[2 * ind + 2]);
}
int query(int ind, int low, int high, int l, int r) {
    if (low >= l && high <= r) return ST[ind]; //total overlap
    if (r < low || high < l) return INT_MIN; //no overlap else go below for partial
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l , r);
    return max(left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /*Input
    5
    1 31 53 7 9
    1 3
    */
    int n;
    cin >> n;
    segtreeinit(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    build(0, 0, n - 1);
    int l, r;
    cin >> l >> r;
    cout << query(0, 0, n - 1, l, r);
    return 0;
}
