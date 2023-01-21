//bfs

class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {


        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j] == 1)
                    {
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
                
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = row + delrow[i]; 
                int ncol = col + delcol[i]; 

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }

        }

        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && vis[i][j]==0) count++;
            }
        }

        return count;
        
    }
};



//dfs - similar to surrounded regions

class Solution {
public:

    
    void dfs(vector<vector<int>>& grid,int i,int j)
    {

        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j] == 1)
        {
            grid[i][j] = 2;
            dfs(grid,i+1,j);
            dfs(grid,i,j+1);
            dfs(grid,i-1,j);
            dfs(grid,i,j-1);
        }
        return ;
    }

    int numEnclaves(vector<vector<int>>& grid) {


        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 1)
            {
                dfs(grid,i,0);
            }

            if(grid[i][m-1] == 1)
            {
                dfs(grid,i,m-1);
            }
        }

        for(int j=0;j<m;j++)
        {
            if(grid[0][j] == 1)
            {
                dfs(grid,0,j);
            }

            if(grid[n-1][j] == 1)
            {
                dfs(grid,n-1,j);
            }
        }

        int count=0;

        for(int i=0;i<n;i++ )
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    count++;
                    grid[i][j] = 0;
                } 
                    

                if(grid[i][j] == 2)
                {
                    grid[i][j] = 0;
                }
            }
        }

        return count;
        
    }
};