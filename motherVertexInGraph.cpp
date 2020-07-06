/*
_._._._._harshvcode_._._._._
# Find mother vertex of a graph.
# Link: https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/
*/
#include<bits/stdc++.h>
using namespace std;
class Graph{
	int siz;
	list<int> *arr;
	public:
		void addEdge(int x, int y);
		Graph(int v);
		void DFSUtil(int x, vector<bool>& visited);
		int findMother();
};
Graph::Graph(int x){
	siz=x;
	arr=new list<int>[siz];
}
void Graph::DFSUtil(int x, vector<bool>& visited){
	visited[x]=true;
	list<int>::iterator it;
	for(it=arr[x].begin(); it!=arr[x].end(); it++){
		if(! visited[*it]) DFSUtil(*it, visited);
	}
}
void Graph::addEdge(int x, int y){
	arr[x].push_back(y);
}
int Graph::findMother(){
	vector<bool> visited(siz, false);
	int mother=0;
	for(int i=0; i<siz; i++){
		if(! visited[i]){
			DFSUtil(i, visited);
			mother=i;
		}
	}
	fill(visited.begin(), visited.end(),false);
	DFSUtil(mother, visited);
	for(int i=0; i<siz; i++){
		if(! visited[i])
			return -1;// If any mother vertex doesn't exist.
	}
	return mother;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	Graph g(7); 
    g.addEdge(0, 1);
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0);
	cout << "Mother vertex: " << g.findMother() << '\n';
	return 0;
}
