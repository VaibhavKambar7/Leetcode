//memoization

#include <bits/stdc++.h> 

int mod = (int)(1e9+7);

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
    
    return dp[ind][sum] =(notpick + pick) % mod;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar + 1,-1));
    return f(n-1,tar,num,dp);
    
}

int countPartitions(int n, int d, vector<int> &arr) {
    
    int totalsum = 0;
    for(auto &it : arr) totalsum += it;
    
    if(totalsum - d < 0 || (totalsum-d) % 2) return false;
    return findWays(arr,(totalsum-d)/2);
    
}




//tabulation


#include <bits/stdc++.h> 
int mod = (int)(1e9+7);
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    if(num[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(num[0] != 0 && num[0] <= tar) dp[0][num[0]] = 1;
    
    for(int i = 1; i < n; i++){
        for(int target = 0; target <= tar; target++){
            int notTaken = dp[i-1][target];
            int taken = 0;
            if(num[i]<=target)
                taken = dp[i-1][target-num[i]];
        
            dp[i][target]= (notTaken + taken) % mod;
        }
    }
    
    return dp[n-1][tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    
    int totalsum = 0;
    for(auto &it : arr) totalsum += it;
    
    if(totalsum - d < 0 || (totalsum-d) % 2) return false;
    return findWays(arr,(totalsum-d)/2);
    
}





//space optimization



#include <bits/stdc++.h> 
int mod = (int)(1e9+7);
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    vector<int> prev(tar+1, 0);
    vector<int> curr(tar+1, 0);
    
    if(num[0]==0) prev[0] = 2;
    else prev[0] = 1;
    if(num[0] != 0 && num[0] <= tar) prev[num[0]] = 1;
    
    for(int i = 1; i < n; i++){
        for(int target = 0; target <= tar; target++){
            int notTaken = prev[target];
            int taken = 0;
            if(num[i]<=target)
                taken = prev[target-num[i]];
        
            curr[target]=(notTaken + taken) % mod;
        }
        prev = curr;
    }
    
    return prev[tar];
}



int countPartitions(int n, int d, vector<int> &arr) {
    
    int totalsum = 0;
    for(auto &it : arr) totalsum += it;

    if(totalsum - d < 0 || (totalsum-d) % 2) return false;
    return findWays(arr,(totalsum-d)/2);
    
 }



