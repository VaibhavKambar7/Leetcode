//tabulation

#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{

        int totsum = 0;

        for(auto x : arr)
        {
            totsum += x;
        }
    
//         for(int i=0;i<n;i++)
//         {
//             totsum += arr[i];
//         }

        int k = totsum;

        vector<vector<bool>> dp(n,vector<bool>(k+1,0));

        for(int i=0;i<n;i++) dp[i][0] = true;

        if(arr[0] <= k) dp[0][arr[0]] = true;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                bool notpick = dp[i-1][j];

                bool pick = false;

                if(j>=arr[i]) pick = dp[i-1][j - arr[i]];

                dp[i][j] = pick or notpick;
            }
        }


        int mini = 1e9;

        for(int s1=0;s1<=totsum/2;s1++)
        {
            if(dp[n-1][s1] == true)
            {
                mini = min(mini,abs((totsum - s1) - s1));
            }
        }

    return mini;
}




//space optimization

#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{

        int totsum = 0;

        for(auto x : arr)
        {
            totsum += x;
        }

        int k = totsum;

        vector<bool> curr(k+1,0);
        vector<bool> prev(k+1,0);

        prev[0] = curr[0] = true;
        prev[arr[0]] = true;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                bool notpick = prev[j];

                bool pick = false;

                if(j>=arr[i]) pick = prev[j - arr[i]];

                curr[j] = pick or notpick;
            }
            
            prev = curr;
        }


        int mini = 1e9;

        for(int s1=0;s1<=totsum/2;s1++)
        {
            if(prev[s1] == true)
            {
                mini = min(mini,abs((totsum - s1) - s1));
            }
        }

    return mini;
}
