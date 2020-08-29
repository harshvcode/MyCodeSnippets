/*
__________By__________
______harshvcode______
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[8];
vector<bool> vis(8, 0);
vector<int> color(8, 0);
bool Cycfound=0;
void dfs(int v, int p){
  color[v] = 1; // GREY
  for(int w : adj[v]){
    if(color[w] == 1){
    	Cycfound=1;
    	return;
    }
    if(color[w] == 0) dfs(w, v);
  }
  color[v] = 2; // BLACK
}
bool iscyclic(int V){
	Cycfound=0;
	for(int i = 0; i < V; i++)
		if(color[i] == 0) dfs(i, -1); // IF NODE IS WHITE, START NEW DFS
	return Cycfound;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("inp.txt","r",stdin);
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[0].push_back(3);
	adj[1].push_back(4);
	adj[1].push_back(5);
	adj[5].push_back(6);
	adj[6].push_back(7);
	adj[7].push_back(1);
	cout << iscyclic(8);//8 is total size
	return 0;
}
