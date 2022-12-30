// recursion
// tle


bool f(int ind, int target, vector<int> &arr)
{
    if(target == 0) return true;
    if(ind == 0) return (arr[0]==target);
    
    bool notpick = f(ind-1,target,arr);
    
    bool pick = false;
    
    if(arr[ind] <= target)
    {
        pick = f(ind-1,target-arr[ind],arr);
    }
    
    return (pick or notpick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    
    return f(n-1,k,arr);
}




// memoization


bool f(int ind, int target, vector<int> &arr,vector<vector<int>> &dp)
{
    if(target == 0) return true;
    if(ind == 0) return (arr[0]==target);
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool notpick = f(ind-1,target,arr,dp);
    
    bool pick = false;
    
    if(arr[ind] <= target)
    {
        pick = f(ind-1,target-arr[ind],arr,dp);
    }
    
    return dp[ind][target] = (pick or notpick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    
    return f(n-1,k,arr,dp);
}





// tabulation


bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<bool >> dp(n,vector<bool>(k+1,0));
    
    for(int i=0;i<n;i++) dp[i][0] = true;
    
    dp[0][arr[0]] = true;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            bool notpick = dp[i-1][j];
    
            bool pick = false;

            if(arr[i] <= j)
            {
                pick = dp[i-1][j-arr[i]];
            }
            
            dp[i][j] = pick or notpick;
        }
        
    }
    
    return dp[n-1][k];
}





//space optimization


bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<bool> prev(k+1,0);
    vector<bool> curr(k+1,0);
    
    for(int i=0;i<n;i++) prev[0] = true;
    for(int i=0;i<n;i++) curr[0] = true;
    
    prev[arr[0]] = true;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            bool notpick = prev[j];
    
            bool pick = false;

            if(arr[i] <= j)
            {
                pick = prev[j-arr[i]];
            }
            
            curr[j] = pick or notpick;
        }
        
        prev = curr;
        
    }
    
    return prev[k];
}


