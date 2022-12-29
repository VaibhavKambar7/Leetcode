// recursion


class Solution {
public:
 
 int fun(int i,int j,vector<vector<int>>& mat)
    {
        if(j>mat.size()-1) return 1e9;
        if(j<0) return 1e9;
        if(i == 0) return mat[i][j];


        int up = mat[i][j] + fun(i-1,j,mat);
        int upl = mat[i][j] + fun(i-1,j-1,mat);
        int upr = mat[i][j] + fun(i-1,j+1,mat);

        return min(up,min(upl,upr));
        

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int mini=1e9;

        int n = matrix.size();
        int m = matrix[0].size();

        for(int j=0;j<m;j++)
        {
            mini = min(mini,fun(n-1,j,matrix));
        }

        return mini;

    }
};






// memoization



class Solution {
public:
 
 int fun(int i,int j,vector<vector<int>>& mat,vector<vector<int>> dp)
    {
        if(j>mat.size()-1) return 1e9;
        if(j<0) return 1e9;
        if(i == 0) return mat[i][j];

        if(dp[i][j] != -1) return dp[i][j];


        int up = mat[i][j] + fun(i-1,j,mat,dp);
        int upl = mat[i][j] + fun(i-1,j-1,mat,dp);
        int upr = mat[i][j] + fun(i-1,j+1,mat,dp);

        return dp[i][j] = min(up,min(upl,upr));
        

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {


        int mini=1e9;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int j=0;j<m;j++)
        {
            mini = min(mini,fun(n-1,j,matrix,dp));
        }

        return mini;

    }
};





// tabulation


class Solution {
public:
 
 
    int minFallingPathSum(vector<vector<int>>& matrix) {


        int mini=1e9;

        int n = matrix.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int j=0;j<n;j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == n-1) dp[n-1][j];

                int up = matrix[i][j] + dp[i-1][j];
                int upl = matrix[i][j] ;
                if (j-1>=0) upl += dp[i-1][j-1];
                else upl += 1e9;

                int upr = matrix[i][j] ;
                if(j+1<n) upr += dp[i-1][j+1];
                else upr += 1e9;

                dp[i][j] = min(up,min(upl,upr));
            }
        }


        for(int j=0;j<n;j++)
        {
            mini = min(mini,dp[n-1][j]);
        }

        return mini;

    }
};





//space optimization


class Solution {
public:
 
 
    int minFallingPathSum(vector<vector<int>>& matrix) {


        int mini=1e9;

        int n = matrix.size();

        vector<int> prev(n,0);
        vector<int> curr(n,0);

        for(int j=0;j<n;j++)
        {
            prev[j] = matrix[0][j];
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == n-1) prev[j];

                int up = matrix[i][j] + prev[j];
                int upl = matrix[i][j] ;
                if (j-1>=0) upl += prev[j-1];
                else upl += 1e9;

                int upr = matrix[i][j] ;
                if(j+1<n) upr += prev[j+1];
                else upr += 1e9;

                curr[j] = min(up,min(upl,upr));
            }

            prev = curr;
        }


        for(int j=0;j<n;j++)
        {
            mini = min(mini,prev[j]);
        }

        return mini;

    }
};


