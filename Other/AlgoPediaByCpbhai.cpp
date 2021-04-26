*************ROUNDOFF DOUBLE BY 2 digits*******************
		double value = 3.1474985;//
 		stringstream tmp;
		tmp << setprecision(2) << fixed << value;
		value = stod(tmp.str());//value is now precision with 2.


************Binary Exponentiation***********************
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main()
{
	cout << binpow(2,6);
	return 0;
}


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


*************Graph Data Structure***************************
#include<bits/stdc++.h>
using namespace std;
int INF=1e5+5;
struct Graph{
  int V;
  vector<vector<pair<int, int>>> G;
  vector<short> VIS;
  void init(int v){
    V=v;
    G.resize(V);
    VIS.resize(V);
  }
  void add(int u, int v, int w = -1){
  	assert(u >= 0 && v >= 0);//ensures +ve vertices
  	G[u].push_back({v,w});
  	//G[v].push_back({u,w});//comment if directed
  }
  void dfs(int v){
  	if(VIS[v]) return;
  	cout << v << " ";
  	VIS[v] = 1;
  	for(auto e : G[v])
  	{
  		if(! VIS[e.first])
  		{
  			dfs(e.first);
  		}
  	}
  }
  void bfs(int v){
  	queue<int> q;
  	q.push(v);
  	VIS[v] = 1;
  	while(! q.empty())
  	{
  		v = q.front();
  		q.pop();
  		cout << v << " ";
  		for(auto e : G[v])
  		{
   			if(! VIS[e.first])
  			{
  				q.push(e.first);
  				VIS[e.first] = 1;
  			}
  		}
  	}
  }
  void resetVis(bool c){//arg is for newline
  	if(c) cout << "\n";
  	fill(VIS.begin(), VIS.begin()+V, 0);
  }
  void utiltopSort(int v, stack<int>& st){
  	if(VIS[v]) return;
  	VIS[v] = 1;
  	for(auto e : G[v])
  	{
  		utiltopSort(e.first, st);
  	}
  	st.push(v);
  }
  void topSort(){
  	stack<int> st;
  	for(int i = 0; i < V; ++i)
  		if(! VIS[i])
  			utiltopSort(i, st);
  	while(! st.empty()) { cout << st.top() << " "; st.pop(); }
  	cout << "\n";
  }
  bool utilcycDir(int v){
  	if(VIS[v] == 1) return 1;
  	if(VIS[v] == 2) return 0;
  	VIS[v] = 1;
  	for(auto e:G[v]){
  		if(utilcycDir(e.first)) return 1;
  	}
  	VIS[v] = 2;
  	return 0;
  }
  bool cycDir(){
  	for(int i=0; i<V; ++i){
  		if(! VIS[i] && utilcycDir(i))
  			return 1;
  	}
  	return 0;
  }
  void priMst(){
  	int src=0;
  	vector<int> dist(V,INF);
  	vector<int> par(V,-1);
  	//VIS will be used to check whether a vertex is in MST.
  	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//weight, vertex
  	pq.push({0,src});
  	VIS[src]=1;
  	dist[src]=0;
  	while(! pq.empty())
  	{
  		int u=pq.top().second;
  		pq.pop();
  		VIS[u]=1;
  		for(auto e:G[u]){
  			int v=e.first;
  			int w=e.second;
  			if(! VIS[v] && dist[v] > w){
  				dist[v]=w;
  				pq.push({dist[v],v});
  				par[v]=u;
  			}
  		}
  	}
  	for(int i=0; i<V; ++i) cout<<par[i]<<"->"<<i<<"\n";
  }
  void dijkstras(int s){//arg is src
  	vector<int> d (V, INF), p(V);
  	d[s] = 0;
  	for (int i=0; i<V; ++i) {
  		int v = -1;
  		for(int j=0; j<V; ++j)
  			if (!VIS[j] && (v == -1 || d[j] < d[v]))
  				v = j;
  		if (d[v] == INF)
  			break;
  		VIS[v] = 1;

  		for (size_t j=0; j<G[v].size(); ++j) {
  			int to = G[v][j].first;
  				int len = G[v][j].second;
  			if (d[v] + len < d[to]) {
  				d[to] = d[v] + len;
  				p[to] = v;
  			}
  		}
  	}
  	for(int i=0; i<V; ++i) cout<<i<<"->"<<d[i]<<"\n";
  }
  void bellmanFord(int src){
    vector<int> dist(V, INF);
    dist[src]=0;
    for(int u=0; u<V; ++u){
      for(auto e:G[u]){
        int v=e.first;
        int w=e.second;
        int tmpDist=dist[u]+w;
        if(tmpDist < dist[v]){
          dist[v]=tmpDist;
        }
      }
    }
    dist[src]=0;
    for(int i=0; i<V; ++i) cout<<i<<"->"<<dist[i]<<"\n";
  }
};
int main(){
  Graph g;
  int V;//size of Graph
  cin >> V;
  g.init(V);
  int n;//no. of edges
  cin >> n;
  for(int i=0; i<n; ++i){
    int u, v;
    cin>>u>>v;
    g.add(u, v);
  }
  cout << g.cycDir();
  return 0;
}


************Split String By Delimeter***********************
vector<string> split(string s,char delim)
{
	vector<string> result;
	int n=s.size(),len=0,b=0;
	for(int i=0 ; i<n ; i++)
	{
		len++;
		if(i==n-1)
		{
			result.push_back(s.substr(b,len));
		}
		else if(s.at(i)==delim)
		{
			result.push_back(s.substr(b,len-1));
			b=i+1;len=0;
		}
	}
	return result;
}


************Range Minimum Query*****************************
const int MAX_N = 500;
int lookup[MAX_N][MAX_N];
void buildSparseTable(vector<int>& arr, int& n)
{
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            if (lookup[i][j - 1] <
                        lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] =
                         lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
int query(int L, int R)
{
    int j = (int)log2(R - L + 1);
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
    else
        return lookup[R - (1 << j) + 1][j];
}
int main()
{
	vector<int> arr = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
	int n = (int)arr.size();
	buildSparseTable(arr, n);
	cout << query(0, 4) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;
	return 0;
}


************Get All Subsets*********************************
vector<vector<int>> getAllSubsets(vector<int> sett)
{
    vector<vector<int>> ans;
    int size = (int)sett.size();
    int no_of_subs = (1 << size);//==2^n
    for(int j = 0; j < no_of_subs; ++j)
    {
        vector<int> subset;
        for(int i = 0; i < size; ++i)
        {
            if((j & (1 << i)) != 0)
            {
                subset.push_back(sett[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}


************Longest Subarray With Sum K*********************
int sol(vector<int> arr, int k) {
	int n = (int)arr.size(), sm = 0, ans = 0;
	unordered_multimap<int, int> mp;
	mp.insert({0, -1});
	for(int i = 0; i < n; ++i) {
		sm += arr[i];
		if(mp.find(sm - k) != mp.end()) {
			auto it= mp.find(sm - k);
			while(it != mp.end() && it->first == sm - k) {
				ans = max(i - (it->second + 1) + 1, ans);
				++it;
			}
		}
		mp.insert({sm, i});
	}
	return ans;
}


****************KMP Substring occurence find***************************
vector<int> prefix_function(string &s)
{
	int n = s.size();
	vector<int> pi(n);
	for(int i = 1; i < n; i++)
	{
		int j = pi[i - 1];
		while(j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> find_occurences(string &text, string &pattern)
{
	string cur = pattern + '#' + text;
	int sz1 = text.size(), sz2 = pattern.size();
	vector<int> v;
	vector<int> lps = prefix_function(cur);
	for(int i = sz2 + 1; i <= sz1 + sz2; i++)
	{
		if(lps[i] == sz2)
			v.push_back(i - 2 * sz2);
	}
	return v;
}


********************Singly LinkedList Implementation**************************
class Node
{
    public:
    int key;
    Node* next;
};
void add(Node** head, int key)//O(1)
{
    Node* new_ = new Node;
    new_->key = key;
    new_->next = *head;
    *head = new_;
}
void append(Node** head, int key)//O(n)
{
    Node* nw_ = new Node();
    nw_->key = key;
    nw_->next = nullptr;
    Node* tmp = *head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = nw_;
}
void trv(Node* head)//O(n)
{
    Node* tmp = head;
    while(tmp != nullptr)
    {
        cout << tmp->key << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}
void solvethetestcase()
{
    Node* head = nullptr;
    FOR(i, 1, 11) add(&head, i);
    trv(head);
    append(&head, 12);
    trv(head);
    trv(head);
}


*******************Doubly LinkedList Implementation*********************
class Node
{
    public :
    int key;
    Node *next, *prev;
};
Node *tail = nullptr;
void add(Node **head, int key)
{
    Node *new_node = new Node();
    new_node->key = key;
    new_node->next = *head;
    new_node->prev = nullptr;
    if(*head == nullptr) tail = new_node;
    else (*head)->prev = new_node;
    *head = new_node;
}
void trvl2r(Node* node)
{
    Node *tmp = node;
    while(tmp != nullptr)
    {
        cout << tmp->key << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}
void trvr2l()
{
    Node *tmp = tail;
    while(tmp != nullptr)
    {
        cout << tmp->key << " ";
        tmp = tmp->prev;
    }
    cout << "\n";
}
void delByVal(Node *head, Node **head_ref, int key)
{
    Node *tmp = head;
    if(tmp->key == key)//if key at head
    {
        *head_ref = tmp->next;
        delete tmp;//deletes pointer created with new(operator)
        return;
    }
    while(tmp->key != key)
    {
        tmp = tmp->next;
        if(tmp == nullptr) return;
    }
    if(tmp->next == nullptr) tmp->prev->next = nullptr;//if key at tail
    else
    {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;//deletes pointer created with new(operator)
    }
}
void solvethetestcase()
{
    Node* head = nullptr;
    FOR(i, 1, 11) add(&head, i);
    trvl2r(head);
    delByVal(head, &head, 10);
    trvl2r(head);

}
