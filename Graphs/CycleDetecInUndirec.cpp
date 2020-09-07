bool cyclic(int s, vector<int> adj[], int vis[], int p)
{   
    
   
      vis[s] = 1;
     
    for(int i = 0;i<adj[s].size();i++)
    {
        if(!vis[adj[s][i]])
        {
          if(cyclic(adj[s][i],adj,vis,s))
          return true;
        }
        else if(vis[adj[s][i]]  && adj[s][i]!=p)
        return true;
    }
   
    return false;
}
bool isCyclic(vector<int> adj[], int V)
{
 int vis[V];
    for(int i = 0;i<V;i++)
    vis[i] = 0;
   for(int i = 0;i<V;i++)
   {   if(!vis[i])
if (cyclic(i,adj,vis,-1))
return true;
   }
   return false;
}
