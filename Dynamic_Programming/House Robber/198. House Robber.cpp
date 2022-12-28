//1) recursion


class Solution {
    public:

    int f(int ind , vector<int>& nums)
    {
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;

        int pick = nums[ind] + f(ind-2,nums);

        int notPick = 0 + f(ind-1,nums);

        return max(pick,notPick);

    }



   int rob(vector<int>& nums) {

        int n = nums.size();
        return f(n-1,nums);

    }
};




//2) memoization


class Solution {
        public:


        int f(int ind , vector<int>& nums,vector<int>& dp)
    {
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + f(ind-2,nums,dp);

        int notPick = 0 + f(ind-1,nums,dp);

        return dp[ind] = max(pick,notPick);

    }



    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
        
    }
};





// 3) tabulation



class Solution {
       public:

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,-1);

        dp[0] = nums[0];

        for(int i=1;i<n;i++)
        {


            int pick = nums[i];
            if(i>1) pick += dp[i-2];

            int notPick = 0 + dp[i-1];

            dp[i] = max(pick,notPick);

        }

        return dp[n-1];
        
    }
};



// 4) space optimization


class Solution {
    public:


      int rob(vector<int>& nums) {

        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;


        for(int i=1;i<n;i++)
        {

            int pick = nums[i];
            if(i>1) pick += prev2;

            int notPick = 0 + prev;
            int curr = max(pick,notPick);
            prev2=prev;
            prev=curr;

        }

        return prev;
        
    }

};