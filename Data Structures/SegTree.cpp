************************Segment Tree************************
#include<bits/stdc++.h>
using namespace std;
struct SegTree{
  static int N;
  vector<int> arr;
  vector<int> ST;
  void init(int n){
    N=n;
    arr.resize(N); ST.resize(N*4);
  }
  void build(int ind, int low, int high){
    if(low==high){
      ST[ind]=arr[low];
      return;
    }
    int mid=(low+high)/2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);
    ST[ind]=max(ST[2*ind+1], ST[2*ind+2]);
  }
  int query(int ind, int low, int high, int l, int r){
    if(low>=l && high<=r) return ST[ind];//total overlap
    if(r<low || high<l) return INT_MIN;//no overlap else go below for partial
    int mid=(low+high)/2;
    int left=query(2*ind+1, low, mid, l, r);
    int right=query(2*ind+2, mid+1, high, l , r);
    return max(left, right);
  }
};
int SegTree::N=0;//static initialization
int main(){;
  SegTree sgt;
  int n;
  cin>>n;
  sgt.init(n);
  for(int i=0; i<n; ++i) cin>>sgt.arr[i];
  sgt.build(0, 0, n-1);
  cout<<sgt.query(0, 0, n-1, QueryFrom, QueryTo);
  }
  return 0;
}
