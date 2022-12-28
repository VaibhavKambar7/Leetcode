//recursion


class Solution {
public:


    int f(int i,int j,vector<vector<int>>& triangle)
    {
        
        if(i>triangle.size()) return 0;
        if(i == triangle.size() - 1) return triangle[i][j];



        int diag = triangle[i][j] + f(i+1,j+1,triangle); 
        int down = triangle[i][j] + f(i+1,j,triangle); 

        return min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        int m = triangle[0].size();


        return f(0,0,triangle);
        
    }
};




// memoization
// tle


class Solution {
public:


    int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> dp)
    {
        
        if(i == triangle.size() - 1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];


        int down = triangle[i][j] + f(i+1,j,triangle,dp); 
        int diag = triangle[i][j] + f(i+1,j+1,triangle,dp); 

        return dp[i][j] = min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n,vector<int> (n,-1));

        return f(0,0,triangle,dp);
        
    }
};






//tabulation




class Solution {
public:


    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n,vector<int> (n,0));

        for(int j=0;j<n;j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {

                int down = triangle[i][j] + dp[i+1][j]; 
                int diag = triangle[i][j] + dp[i+1][j+1]; 

                dp[i][j] = min(down,diag);


            }
        }

        return dp[0][0];

    }
};






//space optimization



class Solution {
public:


    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();


        vector<int> after(n,0);
        vector<int> curr(n,0);

        for(int j=0;j<n;j++)
        {
            after[j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {

                int down = triangle[i][j] + after[j]; 
                int diag = triangle[i][j] + after[j+1]; 

                curr[j] = min(down,diag);


            }

            after = curr;
        }

        return after[0];

    }
};