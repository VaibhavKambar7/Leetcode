// recursion
// tle


class Solution {
public:

    bool f(int ind,int sum,vector<int>& nums)
    {

        if(sum == 0) return true;
        if(ind == 0) return (nums[0] == sum);

        int notpick = f(ind-1,sum,nums);

        int pick = false;

        if(sum>nums[ind])
        {
            pick = f(ind-1,sum - nums[ind],nums);

        }

        return pick || notpick;

    }
 
    bool canPartition(vector<int>& nums) {

        int totalsum = 0;

        for(int i=0;i<nums.size();i++)
        {
            totalsum += nums[i];
        }

        if(totalsum % 2 != 0) return false;

        int sum = totalsum/2;

        return f(nums.size()-1,sum,nums); 

    }
};






// memoization


class Solution {
public:

    bool f(int ind,int sum,vector<int>& nums,vector<vector<int>> &dp)
    {

        if(sum == 0) return true;
        if(ind == 0) return (nums[0] == sum);

        if(dp[ind][sum] != -1) dp[ind][sum];

        int notpick = f(ind-1,sum,nums,dp);

        int pick = false;

        if(sum>nums[ind])
        {
            pick = f(ind-1,sum - nums[ind],nums,dp);

        }

        return dp[ind][sum] = pick || notpick;

    }
 
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int totalsum = 0;

        for(int i=0;i<n;i++)
        {
            totalsum += nums[i];
        }

        if(totalsum % 2 != 0) return false;

        int sum = totalsum/2;

        vector<vector<int>> dp(n,vector<int>(sum+1,-1));

        return f(n-1,sum,nums,dp); 

    }
};





//tabulation



class Solution {
public:

    bool f(int ind,int sum,vector<int>& nums)
    {
        int n = nums.size();

        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));

        for(int i=0;i<n;i++)
        {
            dp[i][0] = true;
        }

        if(nums[0]<=sum) dp[0][nums[0]] = true;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)//1
            {
                
                bool notpick = dp[i-1][j];

                bool pick = false;

                if(j>=nums[i])//2
                {
                    pick = dp[i-1][j - nums[i]];
                }

                dp[i][j] = pick || notpick;
            }
        }

          return dp[n-1][sum]; 
    }

 
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int totalsum = 0;

        for(int i=0;i<n;i++)
        {
            totalsum += nums[i];
        }

        if(totalsum % 2 != 0) return false;

        int sum = totalsum/2;

        return f(n,sum,nums);

    }
};





//space optimization



class Solution {
public:

    bool f(int ind,int sum,vector<int>& nums)
    {
        int n = nums.size();

        vector<bool> prev(sum+1,0);
        vector<bool> curr(sum+1,0);

        for(int i=0;i<n;i++) prev[0] = true;
        for(int i=0;i<n;i++) curr[0] = true;

        prev[0] = curr[0] = true;
        
        if(nums[0]<=sum) prev[nums[0]] = true;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                bool notpick = prev[j];

                bool pick = false;

                if(j>=nums[i])
                {
                    pick = prev[j - nums[i]];
                }

                curr[j] = pick || notpick;
            }

            prev = curr;
        }

          return prev[sum]; 
    }
    

 
    bool canPartition(vector<int>& nums) {

       int n = nums.size();

       int totalsum = 0;

        for(int i=0;i<n;i++)
        {
            totalsum += nums[i];
        }

        if(totalsum % 2) return false;

        int sum = totalsum/2;

        return f(n,sum,nums);

    }
};
