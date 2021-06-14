***********************Binary Indexed Tree Fendwick Tree**********
#include<bits/stdc++.h>
using namespace std;
struct BIT{
  static int N;
  vector<int> arr;
  vector<int> BT;
  void init(int n){
    N=n;
    arr.resize(N);
    BT.resize(N+1);
  }
  int sumOneTo(int R){//sums 1 to R
    int res=0;
    for(; R>0; R-=(R&(-R))) res+=BT[R];
    return res;
  }
  int sumL2R(int L, int R){
    return (sumOneTo(R) - sumOneTo(L-1));//hope func name and arg clears logic behind
  }
  void update(int i, int x){
    arr[i-1]+=x;//updates in arr, below statement does the update in BT
    for(; i<=N; i+=(i&(-i))) BT[i]+=x;//adds x, not replaces
  }
  void build(){
    for(int i=0; i<N; ++i)
      update(i+1, arr[i]);
  }
};
int BIT::N=0;//static initialization
int main(){
  int n;
  cin>>n;
  BIT bt;
  bt.init(n);
  for(int i=0; i<n; ++i) cin>>bt.arr[i];
  bt.build();
  while(true){
    int q; cin>>q;
    if(q==1){int R; cin>>R; cout<<bt.sumOneTo(R)<<"\n";}
    else if(q==2){int L, R; cin>>L>>R; cout<<bt.sumL2R(L, R)<<"\n";}
    else if(q==3){int onebasedindex, val; cin>>onebasedindex>>val; bt.update(onebasedindex, val);}
    else break;
  }
  return 0;
}
