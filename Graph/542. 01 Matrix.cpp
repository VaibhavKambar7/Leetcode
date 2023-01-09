//DFS - brute force
//tc (n x n)^ 2


int dfs(vector<vector<int>>& mat,int x ,int y,vector<vector<bool>>& vis)
{
    if(x<0 || y<0  || x>=mat.size() || y>=mat[0].size() || vis[x][y])
    {
        return 1000000; 
    }
    if(mat[x][y] == 0) return 0;
    vis[x][y] = true;
    int step = 1 + min(min(dfs(mat,x+1,y,vis),dfs(mat,x,y+1,vis)),
    min(dfs(mat,x-1,y,vis),dfs(mat,x,y-1,vis)));

    vis[x][y] = false;

    return step;

}


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis;
        vector<vector<int>> dis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    if(mat[i][j] > 0)
                    {
                        dis[i][j] = dfs(mat,i,j,vis);
                    }
            }
        }

        return dis;

    }
};



//BFS - better
//tc (n x m)
//sc (n x m)


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
        //2 x n x m
        vector<vector<int>> vis(n,vector<int>(m,0));//n x m 
        vector<vector<int>> dis(n,vector<int>(m,0));//n x m

        queue<pair<pair<int,int>,int>> q;
        //n x m
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int delrow[] ={-1,0,1,0}; 
        int delcol[] ={0,1,0,-1}; 


        // n x m x 4
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col] = steps;

            for(int i=0;i<4;i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }

        return dis;

    }
};




//DP - optimal
//tc (n x m)
//sc O(1)



class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    if(mat[i][j] != 0)
                    {
                        int top = i-1 >= 0 ? mat[i-1][j] : 10000;
                        int left = j-1 >= 0 ? mat[i][j-1] : 10000;

                        mat[i][j] = min(top,left) + 1;
                    }
            }
        }


        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j] != 0)
                    {
                        int bottom = i+1 < n ? mat[i+1][j] : 10000;
                        int right = j+1 < m? mat[i][j+1] : 10000;

                        mat[i][j] = min(mat[i][j],min(bottom,right) + 1);
                        
                    }
            }
        }

        return mat;

    }
};





