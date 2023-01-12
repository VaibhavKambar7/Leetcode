class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j)//sird & daalne se 79 se 157 testcases pass hue
    {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j] == '1')//== aayega
        {
            grid[i][j] = '2';
          dfs(grid,i+1,j);
          dfs(grid,i,j+1);
          dfs(grid,i-1,j);
          dfs(grid,i,j-1);
        }
        else {
            return;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        
        return count;
        
    }
};