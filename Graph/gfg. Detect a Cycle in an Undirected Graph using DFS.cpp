class Solution {
  public:
  
    bool detect(int src,int parent,vector<int> adj[],int vis[])
    {
        vis[src] = 1;
        for(auto x : adj[src])
        {
            if(!vis[x])
            {
                if(detect(x,src,adj,vis) == true) return true;
            }
            else if(x!=parent)
            {
                return true;
            }
        }
        
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,-1,adj,vis) == true) return true;
            }
        }
        return false;
    }
};