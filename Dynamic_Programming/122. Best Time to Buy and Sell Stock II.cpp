//recursion

class Solution {
public:

    long f(int ind,int buy,vector<int>& prices,int n)
    {
        
        if(ind == n) return 0;
        long profit =0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1,0,prices,n),
                        0 + f(ind+1,1,prices,n));
        }
        else{
            profit = max(prices[ind] + f(ind+1,1,prices,n),
                        0 + f(ind+1,0,prices,n));
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

       return f(0,1,prices,n);


        
    }
};


//memoization

class Solution {
public:

    int profit = 0;

    int f(int i,int buy,vector<int>& prices,vector<vector<int>> &dp)
    {
        if(i==prices.size()) return 0;

        if(dp[i][buy]!=-1)return dp[i][buy];    

        if(buy)
            profit =max(-prices[i]+f(i+1,0,prices,dp),
                        
                        0 + f(i+1,1,prices,dp));

        else
            profit =max(+prices[i]+f(i+1,1,prices,dp),
            
                        0 + f(i+1,0,prices,dp));


            return dp[i][buy] = profit;

        }


    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return f(0,1,prices,dp);
    }

};



//tabulation


class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int ind = n-1;ind>=0;ind--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                int profit = 0;
                if(buy)
                    profit = max(-prices[ind] + dp[ind+1][0],
                                
                                0 + dp[ind+1][1]);

                else
                    profit = max(prices[ind] + dp[ind+1][1],
                                
                                0 + dp[ind+1][0] );


              dp[ind][buy] = profit;
            }


            }
            return dp[0][1];

    }

};



//space optimization


    class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

       vector<int> ahead(2,0),curr(2,0);



        for(int ind = n-1;ind>=0;ind--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                int profit = 0;
                if(buy)
                    profit = max(-prices[ind] + ahead[0],
                                
                                0 + ahead[1]);

                else
                    profit = max(prices[ind] + ahead[1],
                                
                                0 + ahead[0] );


            }

            ahead = curr;


            }
            return curr[1];

    }

};


//4 variable

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

       vector<int> ahead(2,0),curr(2,0);

       int currBuy,currNotBuy,aheadBuy,aheadNotBuy;
       aheadBuy=0,aheadNotBuy=0;

      


        for(int ind = n-1;ind>=0;ind--)
        {
            
                    currBuy = max(-prices[ind] + aheadNotBuy,
                                
                                0 + aheadBuy);

                    currNotBuy = max(prices[ind] + aheadBuy,
                                
                                0 + aheadNotBuy );



            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;

        }
            return currBuy;

    }

};