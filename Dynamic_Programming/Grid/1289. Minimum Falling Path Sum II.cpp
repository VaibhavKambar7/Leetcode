// recursion
//tle

class Solution {
public:
 
 int fun(int i,int j,vector<vector<int>>& mat)
    {
        if(j<0 || j>mat.size()-1) return 1e9;
        if(i == 0) return mat[i][j];

        int ans = 1e9;

        for(int k=0;k<mat.size();k++)
        {
            if(k==j) continue;
            ans =min(ans,mat[i][j] + fun(i-1,k,mat)) ;
        }

        return ans;
        

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {


        int mini=1e9;

        int n = matrix.size();

        for(int j=0;j<n;j++)
        {
            mini = min(mini,fun(n-1,j,matrix));
        }

        return mini;

    }
};




// memoization
// tle



class Solution {
public:
 
 int fun(int i,int j,vector<vector<int>>& mat,vector<vector<int>> dp)
    {
        if(j<0 || j>mat.size()-1) return 1e9;
        if(i == 0) return mat[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;

        for(int k=0;k<mat.size();k++)
        {
            if(k==j) continue;
            ans =min(ans,mat[i][j] + fun(i-1,k,mat,dp)) ;
        }

        return dp[i][j] = ans;
        

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {


        int mini=1e9;

        int n = matrix.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int j=0;j<n;j++)
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
                int ans = 1e9;

                for(int k=0;k<matrix.size();k++)
                {
                    if(k==j) continue;
                    ans = min(ans,matrix[i][j] + dp[i-1][k]) ;
                }

             dp[i][j] = ans;
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
                int ans = 1e9;

                for(int k=0;k<matrix.size();k++)
                {
                    if(k==j) continue;
                    ans = min(ans,matrix[i][j] + prev[k]) ;
                }

             curr[j] = ans;
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

