// recursion

class Solution {
public:

    int f(int ind,int buy,vector<int>& prices,int fee)
    {
        int profit = 0;
        if(ind == prices.size()) return 0;

        if(buy==1)
        {
            profit = max(-prices[ind] + f(ind+1,0,prices,fee),
                        0 + f(ind+1,1,prices,fee));
        }
        else{
            profit = max(prices[ind] - fee  + f(ind+1,1,prices,fee),
                        0 + f(ind+1,0,prices,fee));
        }

        return profit;

    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        return f(0,1,prices,fee);
        
    }
};




// memoization


class Solution {
public:

    int f(int ind,int buy,vector<int>& prices,int fee,vector<vector<int>> dp)
    {
        int profit = 0;
        if(ind == prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy==1)
        {
            profit = max(-prices[ind] + f(ind+1,0,prices,fee,dp),
                        0 + f(ind+1,1,prices,fee,dp));
        }
        else{
            profit = max(prices[ind] - fee  + f(ind+1,1,prices,fee,dp),
                        0 + f(ind+1,0,prices,fee,dp));
        }

        return dp[ind][buy]=profit;

    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return f(0,1,prices,fee,dp);
        
    }
};





// tabulation


class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int ind = n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                 if(buy==1)
                    {
                        dp[ind][buy] = max(-prices[ind] + dp[ind+1][0],
                                    0 + dp[ind+1][1]);
                    }
                    else{
                        dp[ind][buy]  = max(prices[ind] - fee  + dp[ind+1][1],
                                    0 + dp[ind+1][0]);
                    }
            }

        }
            return dp[0][1] ;

        
    }
};






// space optimization

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<int> after(2,0);
        vector<int> curr(2,0);

        for(int ind = n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                 if(buy==1)
                    {
                        curr[buy] = max(-prices[ind] + after[0],
                                    0 + after[1]);
                    }
                    else{
                        curr[buy]  = max(prices[ind] - fee  + after[1],
                                    0 + after[0]);
                    }
            }

            after = curr;

        }
            return curr[1] ;

        
    }
};







// space optimization
// removed internal buy loop

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<int> after(2,0);
        vector<int> curr(2,0);

        for(int ind = n-1;ind>=0;ind--)
        {
                        curr[1] = max(-prices[ind] + after[0],
                                    0 + after[1]);
                    
                        curr[0]  = max(prices[ind] - fee  + after[1],
                                    0 + after[0]);

            after = curr;

        }
            return curr[1] ;

        
    }
};







//4 variable

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();


        int aheadBuy,aheadNotBuy,currBuy,currNotBuy;
        aheadNotBuy=aheadBuy=0;

        for(int ind = n-1;ind>=0;ind--)
        {
                        currBuy = max(-prices[ind] + aheadNotBuy,
                                    0 + aheadBuy);
                    
                        currNotBuy  = max(prices[ind] - fee  + aheadBuy,
                                    0 + aheadNotBuy);

            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;

        }
            return currBuy ;

        
    }
};





