// recursion


#include <bits/stdc++.h> 

int f(int ind,int W,vector<int>& wt, vector<int>& val)
{
    if(ind == 0)
    {
        if(wt[0]<=W) return val[0];
        return 0;
    }
    
    int notpick = 0 + f(ind-1,W,wt,val);
    
    int pick = INT_MIN;
    
    if(wt[ind]<=W)
    {
        pick = val[ind] + f(ind-1,W-wt[ind],wt,val);
    }
    
    return max(pick,notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    
    return f(n-1,maxWeight,weight,value);

}




// memoization


#include <bits/stdc++.h> 

int f(int ind,int W,vector<int>& wt, vector<int>& val,vector<vector<int>>& dp)
{
    if(ind == 0)
    {
        if(wt[0]<=W) return val[0];
        return 0;
    }
    if(dp[ind][W] != -1) return dp[ind][W];
    
    int notpick = 0 + f(ind-1,W,wt,val,dp);
    
    int pick = INT_MIN;
    
    if(wt[ind]<=W)
    {
        pick = val[ind] + f(ind-1,W-wt[ind],wt,val,dp);
    }
    
    return dp[ind][W] = max(pick,notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    
    return f(n-1,maxWeight,weight,value,dp);
    
}





// tabulation


#include <bits/stdc++.h> 

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    
    for(int W=wt[0];W<=maxWeight;W++) dp[0][W] = val[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int W=0;W<=maxWeight;W++)
        {
            int notpick = 0 + dp[ind-1][W];
    
            int pick = INT_MIN;

            if(wt[ind]<=W)
            {
                pick = val[ind] + dp[ind-1][W-wt[ind]];
            }

            dp[ind][W] = max(pick,notpick);
            
        }
    }
    
    return dp[n-1][maxWeight];
}





// space optimization


#include <bits/stdc++.h> 

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    
    vector<int> prev(maxWeight+1,0);
    vector<int> curr(maxWeight+1,0);
        

    
    for(int W=wt[0];W<=maxWeight;W++) prev[W] = val[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int W=0;W<=maxWeight;W++)
        {
            int notpick = 0 + prev[W];
    
            int pick = INT_MIN;

            if(wt[ind]<=W)
            {
                pick = val[ind] + prev[W-wt[ind]];
            }

            curr[W] = max(pick,notpick);
            
        }
        prev = curr;
    }
    
    return prev[maxWeight];
}





//one array optimization


#include <bits/stdc++.h> 

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    
    vector<int> prev(maxWeight+1,0);
    
    for(int W=wt[0];W<=maxWeight;W++) prev[W] = val[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int W=maxWeight;W>=0;W--)
        {
            int notpick = 0 + prev[W];
    
            int pick = INT_MIN;

            if(wt[ind]<=W)
            {
                pick = val[ind] + prev[W-wt[ind]];
            }

            prev[W] = max(pick,notpick);
            
        }
    }
    
    return prev[maxWeight];
}