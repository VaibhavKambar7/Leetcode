//MEHTHOD 1

//recursion
//time limit exceeded

class Solution {
public:

    int f(int ind,int buy,int cap,vector<int>& prices,int n)
    {
        int profit = 0;
        if(ind == n || cap == 0) return 0;

        if(buy)
        {
            profit = max(-prices[ind] + f(ind+1,0,cap,prices,n),
                        0 + f(ind+1,1,cap,prices,n) );
        }

        else{
            profit = max(prices[ind] + f(ind+1,1,cap-1,prices,n),
                        0 + f(ind+1,0,cap,prices,n) ); 
        }

        return profit;
    }


    int maxProfit(vector<int>& prices) {

        int n = prices.size();


       return f(0,1,2,prices,n);
        
    }
};




//memoization

class Solution {
public:

    int f(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>> &dp)
    {
        int profit = 0;
        if(ind == n || cap == 0) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if(buy)
        {
            profit = max(-prices[ind] + f(ind+1,0,cap,prices,n,dp),
                        0 + f(ind+1,1,cap,prices,n,dp) );
        }

        else{
            profit = max(prices[ind] + f(ind+1,1,cap-1,prices,n,dp),
                        0 + f(ind+1,0,cap,prices,n,dp) ); 
        }

        return dp[ind][buy][cap] = profit;
    }


    int maxProfit(vector<int>& prices) {

        int n = prices.size();
       vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));

       return f(0,1,2,prices,n,dp);
        
    }
};




//tabulation


class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
       vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> (2,vector<int> (3,0)));

       for(int ind = n-1;ind >= 0; ind--)
       {
           for(int buy=0;buy<=1;buy++)
           {
               for(int cap=1;cap<=2;cap++)
               {
                   if(buy==1)
                    {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],
                                    0 + dp[ind+1][1][cap] );
                    }

                    else{
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1],
                                    0 + dp[ind+1][0][cap] ); 
                    }
               }
           }
       }

       return dp[0][1][2];
        
    }
};









//space optimization


class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
       vector<vector<int>> after (2,vector<int> (3,0));
       vector<vector<int>> curr (2,vector<int> (3,0));

       for(int ind = n-1;ind >= 0; ind--)
       {
           for(int buy=0;buy<=1;buy++)
           {
               for(int cap=1;cap<=2;cap++)
               {
                   if(buy==1)
                    {
                        curr[buy][cap] = max(-prices[ind] + after[0][cap],
                                    0 + after[1][cap] );
                    }

                    else{
                        curr[buy][cap] = max(prices[ind] + after[1][cap-1],
                                    0 + after[0][cap] ); 
                    }
               }

           }
               after = curr;
       }

       return curr[1][2];
        
    }
};










//METHOD 2 
//recursion



class Solution {
public:

    int f(int ind,int trans,vector<int>& prices,int n)
    {
        int profit = 0 ;
        if(ind == n || trans == 4) return 0;

        if(trans%2==0)
        {
            profit = max(-prices[ind] + f(ind+1,trans+1,prices,n),
                        0 + f(ind+1,trans,prices,n) );
        }

        else{
            profit = max(prices[ind] + f(ind+1,trans+1,prices,n),
                        0 + f(ind+1,trans,prices,n) );
        }

        return profit;

    }

    int maxProfit(vector<int>& prices) {

      int n = prices.size();

      return f(0,0,prices,n);
        
    }
};



// memoization


class Solution {
public:

    int f(int ind,int trans,vector<int>& prices,vector<vector<int>> &dp)
    {
        int profit = 0 ;
        if(ind == prices.size() || trans == 4) return 0;
        if(dp[ind][trans] != -1) return dp[ind][trans];

        if(trans%2==0)
        {
            profit = max(-prices[ind] + f(ind+1,trans+1,prices,dp),
                        0 + f(ind+1,trans,prices,dp) );
        }

        else{
            profit = max(prices[ind] + f(ind+1,trans+1,prices,dp),
                        0 + f(ind+1,trans,prices,dp) );
        }

        return dp[ind][trans] = profit;

    }

    int maxProfit(vector<int>& prices) {

      int n = prices.size();
      vector<vector<int>> dp(n, vector<int> (4,-1));

      return f(0,0,prices,dp);
        
    }
};



//tabulation

class Solution {
public:

    int maxProfit(vector<int>& prices) {

      int n = prices.size();
      vector<vector<int>> dp(n+1, vector<int> (4+1,0));

      for(int ind = n-1;ind >=0 ;ind--)
      {
          for(int trans = 3;trans>=0;trans--)
          {
               if(trans%2==0)
                {
                    dp[ind][trans] = max(-prices[ind] + dp[ind+1][trans+1],
                                0 + dp[ind+1][trans] );
                }

                else{
                    dp[ind][trans] = max(prices[ind] + dp[ind+1][trans+1],
                                0 + dp[ind+1][trans] );
                }
          }
      }
      return dp[0][0];
        
    }
};







// space optimization


class Solution {
public:

    int maxProfit(vector<int>& prices) {

      int n = prices.size();
      vector<int> after(4+1,0);
      vector<int> curr(4+1,0);

      for(int ind = n-1;ind >=0 ;ind--)
      {
          for(int trans = 3;trans>=0;trans--)
          {
               if(trans%2==0)
                    curr[trans] = max(-prices[ind] + after[trans+1],
                                0 + after[trans] );
                }

                else{
                    curr[trans] = max(prices[ind] + after[trans+1],
                                0 + after[trans] );
                }
          }
          after = curr;
      }
      return curr[0];
        
    }
};




