/*
__________By__________
______harshvcode______
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[8];
vector<bool> vis(8, 0);
vector<int> color(8, 0);//Default Color 0 = White
bool Cycfound=0;//Becomes true if there is a cycle
void checkCycle(int v){
	color[v] = 1; // GREY
  	for(int w : adj[v]){
    	if(color[w] == 1){
    		Cycfound=1;
    		return;
    	}
    	if(color[w] == 0) checkCycle(w);
  	}
  	color[v] = 2; // BLACK
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("inp.txt","r",stdin);
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[0].push_back(3);
	adj[1].push_back(4);
	adj[1].push_back(5);
	adj[5].push_back(6);
	adj[6].push_back(7);
	adj[7].push_back(2);
	checkCycle(0);
	cout << Cycfound;
	return 0;
}
