class Solution {
  public:
  
    bool detect(int src,vector<int> adj[],int vis[])
    {
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto x : adj[node])
            {
                if(!vis[x])
                {
                    vis[x] = 1;
                    q.push({x,node});
                }
                else if(parent != x)
                {
                    return true;
                }
            }
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V] ={0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
        
    }
};