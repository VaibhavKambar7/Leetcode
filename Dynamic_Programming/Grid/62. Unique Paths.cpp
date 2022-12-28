//recursion
//tle


class Solution {
public:

    int grid(int i,int j)
    {
        if(i==0 && j==0) return 1;

        if(i<0 || j<0) return 0;

        int up = grid(i-1,j);
        int left = grid(i,j-1);

        return up + left;
    }

    int uniquePaths(int m, int n) {

        return grid(n-1,m-1);
        
    }
};





// memoization
// tle

class Solution {
public:

    int grid(int i,int j,vector<vector<int>> dp)
    {
        if(i==0 && j==0) return 1;

        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = grid(i-1,j,dp);
        int left = grid(i,j-1,dp);

        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return grid(n-1,m-1,dp);
        
    }
};





// tabulation


class Solution {
public:

    int uniquePaths(int m, int n) {


        int dp[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0) dp[i][j]=1;

                else{
                
                int up = 0;
                int left = 0;

                if(i>0)
                up = dp[i-1][j];

                if(j>0)
                left = dp[i][j-1];

                dp[i][j] = up + left;
                }
            }
        }


        return dp[n-1][m-1];
        
    }
};






// space optimization


class Solution {
public:

    int uniquePaths(int m, int n) {


        vector<int> prev(m,0);
        vector<int> curr(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0) curr[j]=1;

                else{
                
                    int up = 0;
                    int left = 0;

                    if(i>0) up = prev[j];

                    if(j>0) left = curr[j-1];

                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return curr[m-1];
    }
};




// another approach


class Solution {
public:


    int uniquePaths(int m, int n) {

        int N = n+m-2;
        int r = m-1;

        double res = 1;

        for(int i=1;i<=r;i++)
        {
            res = res*(N-r+i)/i;
        }

        return res;


    }

    
};
