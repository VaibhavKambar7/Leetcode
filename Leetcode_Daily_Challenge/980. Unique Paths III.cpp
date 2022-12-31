
class Solution {
public:

    int res=0;
    int empty=1;

    void dfs(vector<vector<int>>& grid,int x,int y,int count)
    {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y] == -1) return;

        if(grid[x][y]==2){
            if(empty == count) res++;
                return;
            

        }
        grid[x][y] = -1;
        dfs(grid, x+1, y,   count+1);
        dfs(grid, x-1, y,   count+1);
        dfs(grid, x,   y+1, count+1);
        dfs(grid, x ,  y-1, count+1);

        grid[x][y]=0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        int sx,sy;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1) sx=i,sy=j;
                else if(grid[i][j] == 0){
                     empty++;
                }
            }
        }

        dfs(grid,sx,sy,0);

        return res;
        
    }
};