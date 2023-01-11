class Solution {
public:
    
    int DFS(vector<vector<int>>& adj, int curr, int parent, vector<bool>& hasApple) {
       
        int time = 0;
        
        for(int &child : adj[curr]) {
            if(child != parent)
            {
                int time_from_child = DFS(adj, child, curr, hasApple);
            
                if(time_from_child|| hasApple[child])
                    time += 2 + time_from_child;
            
            }
            
        }
        
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<vector<int>> adj(n);
        
       for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return DFS(adj, 0, -1, hasApple);
    }
};