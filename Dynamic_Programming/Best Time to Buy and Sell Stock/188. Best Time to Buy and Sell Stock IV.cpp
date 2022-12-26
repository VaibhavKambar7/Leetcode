//recursion

class Solution {
public:

    int f(int ind,int trans,vector<int>& prices,int k)
    {
        int profit = 0;
        if(ind == prices.size() || trans == 2*k) return 0;

        if(trans%2==0)
        {
            profit = max(-prices[ind] + f(ind+1,trans+1,prices,k),
                        0 + f(ind+1,trans,prices,k) );
        }
        else{
            profit = max(prices[ind] + f(ind+1,trans+1,prices,k),
                        0 + f(ind+1,trans,prices,k) );
        }

        return profit;

    }

    int maxProfit(int k, vector<int>& prices) {

        return f(0,0,prices,k);
        
    }
};





//memoization


class Solution {
public:

    int f(int ind,int trans,vector<int>& prices,int k,vector<vector<int>> &dp)
    {
        int profit = 0;
        if(ind == prices.size() || trans == 2*k) return 0;

        if(dp[ind][trans] != -1) return dp[ind][trans];


        if(trans%2==0)
        {
            profit = max(-prices[ind] + f(ind+1,trans+1,prices,k,dp),
                        0 + f(ind+1,trans,prices,k,dp) );
        }
        else{
            profit = max(prices[ind] + f(ind+1,trans+1,prices,k,dp),
                        0 + f(ind+1,trans,prices,k,dp) );
        }

        return dp[ind][trans] = profit;

    }

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2*k,-1));

        return f(0,0,prices,k,dp);
        
    }
};





//tabulation


class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n+1 ,vector<int>(2*k+1,0));

        for(int ind = n-1;ind>=0;ind--)
        {
            for(int trans=2*k-1;trans>=0;trans--)
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







//space optimization


class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<int> after(2*k+1,0);
        vector<int> curr(2*k+1,0);

        for(int ind = n-1;ind>=0;ind--)
        {
            for(int trans=2*k-1;trans>=0;trans--)
                {
                    if(trans%2==0)
                    {
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