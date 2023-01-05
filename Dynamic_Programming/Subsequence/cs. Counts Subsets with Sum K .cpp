// recursion

#include <bits/stdc++.h> 

int f(int ind,int sum,vector<int>& nums)
{
    int n = nums.size();

    if(sum == 0) return true;
    
    if(ind == 0) return (nums[0]==sum);
    
    int notpick = f(ind-1,sum,nums);
    
    int pick = false;
    
    if(nums[ind] <= sum)
    {
        pick = f(ind-1,sum-nums[ind],nums);
    }
    
    return notpick + pick;
    
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    return f(n-1,tar,num);
    
}


// memoization


#include <bits/stdc++.h> 

int f(int ind,int sum,vector<int>& num,vector<vector<int>>& dp)
{
    int n = num.size();

    
      if(ind == 0){
        if(sum==0 && num[0]==0)return 2;
        if(sum==0 || sum==num[0])return 1;
        return 0;
      }
    
    if(dp[ind][sum] != -1) return dp[ind][sum];
    
    int notpick = f(ind-1,sum,num,dp);
    
    int pick = 0;
    
    if(num[ind] <= sum)
    {
        pick = f(ind-1,sum-num[ind],num,dp);
    }
    
    return dp[ind][sum] = notpick + pick;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar + 1,-1));
    return f(n-1,tar,num,dp);
    
}



//tabulation


#include <bits/stdc++.h> 
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(num[0] <= tar) dp[0][num[0]] = 1;
    if(num[0] == 0) dp[0][0] = 2;
    
    for(int i = 1; i < n; i++){
        for(int target = 0; target <= tar; target++){
            int notTaken = dp[i-1][target];
            int taken = 0;
            if(num[i]<=target)
                taken = dp[i-1][target-num[i]];
        
            dp[i][target]= notTaken + taken;
        }
    }
    
    return dp[n-1][tar];
}




//space optimization


#include <bits/stdc++.h> 
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    vector<int> prev(tar+1, 0);
    vector<int> curr(tar+1, 0);
    
    
    for(int i = 0; i < n; i++) prev[0] = 1;
    if(num[0] <= tar) prev[num[0]] = 1;
    if(num[0] == 0) prev[0] = 2;
    
    for(int i = 1; i < n; i++){
        for(int target = 0; target <= tar; target++){
            int notTaken = prev[target];
            int taken = 0;
            if(num[i]<=target)
                taken = prev[target-num[i]];
        
            curr[target]= notTaken + taken;
        }
        prev = curr;
    }
    
    return prev[tar];
}


