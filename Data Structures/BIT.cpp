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
vector<int> BT;
void bitinit(int n) {
  N = n;
  arr.resize(N);
  BT.resize(N + 1);
}
int sumOneTo(int R) { //sums 1 to R
  int res = 0;
  for (; R > 0; R -= (R & (-R))) res += BT[R];
  return res;
}
int sumL2R(int L, int R) {
  return (sumOneTo(R) - sumOneTo(L - 1)); //hope func name and arg clears logic behind
}
void update(int i, int x) {
  arr[i - 1] += x; //updates in arr, below statement does the update in BT
  for (; i <= N; i += (i & (-i))) BT[i] += x; //adds x, not replaces
}
void build() {
  for (int i = 0; i < N; ++i)
    update(i + 1, arr[i]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;//Input: 5 11 45 6 34 97
  cin >> n;
  bitinit(n);
  f(n) cin >> arr[i];
  build();
  cout << sumL2R(3, 4) << "\n";
  update(3, 94);
  cout << sumL2R(3, 4);
  return 0;
}
