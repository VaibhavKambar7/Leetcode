// recursion
// tc - exponential, more than 2^n
// sc - more than O(n)

class Solution {
public:

    int f(int ind,int T,vector<int>& coins)
    {
        if(ind == 0)
        {
            if(T % coins[0] == 0) return T / coins[0];
            return 1e9;
        }

        int notpick = 0 + f(ind-1,T,coins);

        int pick = INT_MAX;

        if(coins[ind]<=T)
        {
            pick = 1 + f(ind,T-coins[ind],coins);
        }            

        return min(pick,notpick);

    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        int ans = f(n-1,amount,coins);

        if(ans >= 1e9) return -1;
        return ans;
        
    }
};




// memoization
// tc - O(n x T)
// sc - O(n x T) + O(T)

class Solution {
public:

    int f(int ind,int T,vector<int>& coins,vector<vector<int>> dp)
    {
        if(ind == 0)
        {
            if(T % coins[0] == 0) return T / coins[0];
            return 1e9;
        }

        if(dp[ind][T] != -1) return dp[ind][T];

        int notpick = 0 + f(ind-1,T,coins,dp);

        int pick = INT_MAX;

        if(coins[ind]<=T)
        {
            pick = 1 + f(ind,T-coins[ind],coins,dp);
        }            

        return dp[ind][T] = min(pick,notpick);

    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = f(n-1,amount,coins,dp);

        if(ans >= 1e9) return -1;

        return ans;
        
    }
};




// tabulation
// tc - O(n x T)
// sc - O(n x T) 

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        for(int T=0;T<=amount;T++) 
        {
            if(T % coins[0] == 0)  dp[0][T] = T / coins[0];
            else dp[0][T] = 1e9;
        }

        for(int ind = 1;ind<n;ind++)
        {
            for(int T=0;T<=amount;T++)
            {
                int notpick = 0 + dp[ind-1][T];

                int pick = INT_MAX;

                if(coins[ind]<=T)
                {
                    pick = 1 + dp[ind][T-coins[ind]];
                }            

                dp[ind][T] = min(pick,notpick);
            }
        }

        int ans = dp[n-1][amount];

        if(ans >= 1e9) return -1;

        return ans;

    }
};





//space optimisation
//tc - O(n x T)
//sc - O(T) 


class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();


        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);

        for(int T=0;T<=amount;T++) 
        {
            if(T % coins[0] == 0)  prev[T] = T / coins[0];
            else prev[T] = 1e9;
        }


        for(int ind = 1;ind<n;ind++)
        {
            for(int T=0;T<=amount;T++)
            {
                int notpick = 0 + prev[T];

                int pick = INT_MAX;

                if(coins[ind]<=T)
                {
                    pick = 1 + curr[T-coins[ind]];
                }            

                curr[T] = min(pick,notpick);
            }
            prev = curr;
        }

        int ans = prev[amount];

        if(ans >= 1e9) return -1;

        return ans;

    }
};






