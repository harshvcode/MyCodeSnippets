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


*************Graph Data Structure***************************
class Vertex
{
	public:
	int v, w;
	Vertex(int vv,int ww) { v = vv; w = ww; }
};
map<int, vector<Vertex>> G;
vector<bool> VIS(100);
void add(int u, int v, int w = -1)
{
	assert(u >= 0 && v >= 0);//ensures +ve vertices
	G[u].push_back(Vertex(v, w));
	//G[v].push_back(Vertex(u, w));//comment if directed
}
void dfs(int v)
{
	if(VIS[v]) return;
	cout << v << " ";
	VIS[v] = 1;
	for(Vertex e : G[v])
	{
		if(! VIS[e.v])
		{
			dfs(e.v);
		}
	}
}
void bfs(int v)
{
	queue<int> q;
	q.push(v);
	VIS[v] = 1;
	while(! q.empty())
	{
		v = q.front();
		q.pop();
		cout << v << " ";
		for(Vertex e : G[v])
		{
 			if(! VIS[e.v])
			{
				q.push(e.v);
				VIS[e.v] = 1;
			}
		}
	}
}
void resetVis(bool c)//arg is for newline
{
	if(c) cout << "\n";
	for(int i = 0; i < 101; ++i) VIS[i] = false;
}
void cycDirUtil(int v, bool& found, bitset<100>& recStack)
{
	if(VIS[v])
	{
		if(recStack[v]) found = 1;
		return;
	}
	VIS[v] = 1; recStack.set(v);
	for(Vertex e : G[v])
	{
		if(e.v == v) { found = 1; continue; }//selfLoop
		cycDirUtil(e.v, found, recStack);
	}
	recStack.reset(v);
}
bool cycleDirec()
{
	bool found = false;
	bitset<100> recStack;
	cycDirUtil(0, found, recStack);//starts from zero
	return found;
}
void cycUndUtil(int v, int par, bool& found)
{
	if(VIS[v])
	{
		found = 1;
		return;
	}
	VIS[v] = 1;
	for(Vertex e : G[v])
	{
		if(e.v == v) { found = 1; continue; }//selfLoop
		if(e.v != par)
			cycUndUtil(e.v, v, found);
	}
}
bool cycleUnd()
{
	bool found = false;
	cycUndUtil(0, -1, found);//starts from zero
	return found;
}
void utiltopSort(int v, stack<int>& st)
{
	if(VIS[v]) return;
	VIS[v] = 1;
	for(Vertex e : G[v])
	{
		utiltopSort(e.v, st);
	}
	st.push(v);
}
void topSort()
{
	stack<int> st;
	for(int i = 0; i < 6; ++i)
		if(! VIS[i])
			utiltopSort(i, st);
	while(! st.empty()) { cout << st.top() << " "; st.pop(); }
	cout << "\n";
}
int main()
{
	for(int i = 0; i < 6; ++i)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
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
*******************Template Done until 117 line no.*********************
// --------------------------------------------------<TEMPLATE>-------------------------------------------------- 
// --------------------<optimizations>-------------------- 
 
/* 
#pragma GCC optimize("Ofast,unroll-loops") 
#pragma GCC target("avx,avx2,fma") 
*/  
 
// -------------------</optimizations>-------------------- 
  
// ---------------<Headers and namespaces>---------------- 
#include <bits/stdc++.h> 
using namespace std; 
  
/* 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
*/ 
  
// ---------------</Headers and namespaces>--------------- 
  
// -----------------<Defines and typedefs>---------------- 
// typedef tree<int,null_type,less<int>,rb_tree_tag, \ 
tree_order_statistics_node_update> indexed_set; // use less_equal for multiset 
// order_of_key (val): returns the no. of values less than val 
// find_by_order (k): returns the iterator to kth largest element.(0-based) 
  
typedef long double LD; 
typedef long long ll; 
#define int ll 
#define pb push_back 
#define mp make_pair 
#define REP(i,n) for (int i = 0; i < n; i++) 
#define FOR(i,a,b) for (int i = a; i < b; i++) 
#define REPD(i,n) for (int i = n-1; i >= 0; i--) 
#define FORD(i,a,b) for (int i = a; i >= b; i--) 
#define remax(a,b) a = max(a,b) 
#define remin(a,b) a = min(a,b) 
#define all(v) v.begin(),v.end() 
typedef map<int,int> mii; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
#define F first 
#define S second 
#define PQ(type) priority_queue<type> 
#define PQD(type) priority_queue<type,vector<type>,greater<type> > 
#define WL(t) while(t --) 
#define SZ(x) ((int)(x).size()) 
#define runtime() ((double)clock() / CLOCKS_PER_SEC) 
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b))) 
  
/* 
// -----<SCANF>----- 
#define sfi(x) scanf("%d",&x); 
#define sfi2(x,y) scanf("%d%d",&x,&y); 
#define sfi3(x,y,z) scanf("%d%d%d",&x,&y,&z); 
  
#define sfl(x) scanf("%lld",&x); 
#define sfl2(x,y) scanf("%lld%lld",&x,&y); 
#define sfl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z); 
#define sfl4(x,y,z,x1) scanf("%lld%lld%lld%lld",&x,&y,&z,&x1); 
#define sfl5(x,y,z,x1,y1) scanf("%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1); 
#define sfl6(x,y,z,x1,y1,z1) scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1,&z1); 
  
#define sfs(x) scanf("%s",x); 
#define sfs2(x,y) scanf("%s%s",x,y); 
#define sfs3(x,y,z) scanf("%s%s%s",x,y,z); 
// ----</SCANF>----- 
  
// ----<PRINTF>----- 
#define pfi(x) printf("%d\n",x); 
#define pfi2(x,y) printf("%d %d\n",x,y); 
#define pfi3(x,y,z) printf("%d %d %d\n",x,y,z); 
  
#define pfl(x) printf("%lld\n",x); 
#define pfl2(x,y) printf("%lld %lld\n",x,y); 
#define pfl3(x,y,z) printf("%lld %lld %lld\n",x,y,z); 
  
#define pfs(x) printf("%s\n",x); 
#define pfs2(x,y) printf("%s %s\n",x,y); 
#define pfs3(x,y,z) printf("%s %s %s\n",x,y,z); 
  
#define pwe(x) printf("%lld ",x); // print without end 
// ----</PRINTF>---- 
*/ 
 
#define FLSH fflush(stdout) 
/*#define fileIO(name) \ 
    freopen(name".in", "r", stdin); \ 
    freopen(name".out", "w", stdout); */
#define PRECISION(x) cout << fixed << setprecision(x);  
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
  
// ----------------</Defines and typedefs>---------------- 
  
// -------------------<Debugging stuff>------------------- 
#define TRACE 
  
#ifdef TRACE 
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> 
void __f(const char* name, Arg1&& arg1){ 
    cout << name << " : " << arg1 << std::endl; 
} 
template <typename Arg1, typename... Args> 
void __f(const char* names, Arg1&& arg1, Args&&... args){ 
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...); 
} 
#else 
#define trace(...) 
#endif 
  
// ------------------</Debugging stuff>------------------- 
  
// ------------------------<Consts>----------------------- 
const int MAXN = 1000005; 
const int SQRTN = 1003; 
const int LOGN = 22; 
const double PI=acos(-1); 
  
#ifdef int 
const int INF=1e16; 
#else 
const int INF=1e9; 
#endif 
  
const int MOD = 1000000007; 
const int FMOD = 998244353; 
const double eps = 1e-9; 
 
// -----------------------</Consts>----------------------- 
 
/* 
 
// -------------------------<RNG>------------------------- 
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers. 
  
// ------------------------</RNG>------------------------- 
  
// ----------------------<MATH>--------------------------- 
 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 
int add(int a, int b, int c = MOD){int res=a+b;return(res>=c?res-c:res);} 
int mod_neg(int a, int b, int c = MOD){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);} 
int mul(int a, int b, int c = MOD){ll res=(ll)a*b;return(res>=c?res%c:res);} 
int muln(int a, int b, int c = MOD){ll res=(ll)a*b;return ((res%c)+c)%c;} 
ll mulmod(ll a,ll b, ll m = MOD){ll q = (ll)(((LD)a*(LD)b)/(LD)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;} 
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;} 
template<typename T>T power(T e, T n, T m = MOD){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;} 
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\ 
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;} 
template<typename T>T mod_inverse(T a, T n = MOD){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));} 
  
const int FACSZ = 1; // Make sure to change this 
  
int fact[FACSZ],ifact[FACSZ]; 
  
void precom(int c = MOD){ 
    fact[0] = 1; 
    FOR(i,1,FACSZ) fact[i] = mul(fact[i-1],i,c); 
    ifact[FACSZ-1] = mod_inverse(fact[FACSZ-1],c); 
    REPD(i,FACSZ-1){ 
        ifact[i] = mul(i+1,ifact[i+1],c); 
    } 
} 
  
int ncr(int n,int r,int c = MOD){ 
    return mul(mul(ifact[r],ifact[n-r],c),fact[n],c); 
}  
*/ 
 
// ----------------------</MATH>-------------------------- 
// --------------------------------------------------</TEMPLATE>-------------------------------------------------- 
  
void solvethetestcase(); 
  
signed main(){ 
    // comment when using scanf,printf 
    FAST_IO 
 
    int t = 1; 
    // (UNCOMMENT FOR MULTIPLE TEST CASES) \ 
    cin >> t; 
    FOR(testcase,1,t+1){ 
        // (UNCOMMENT FOR CODEJAM) \ 
        printf("Case #%lld: ",testcase);  
        solvethetestcase(); 
    } 
}    
  
int n; 
  
void solvethetestcase(){ 
    cin >> n; 
 
}