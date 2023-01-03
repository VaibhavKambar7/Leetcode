class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        vector<vector<int>> ans = grid;
        int n = ans.size();
        int m = ans[0].size();

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
            }
        }

        int time=0;
        int maxtime=0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            maxtime = max(maxtime , time);
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && ans[nrow][ncol] == 1)
                {
                    ans[nrow][ncol] = 2; 
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(ans[i][j] == 1)
                    {
                        return -1;
                    }
                }
            }

        return maxtime;
    }
};