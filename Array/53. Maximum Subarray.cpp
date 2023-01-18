// brute force 
// tc - O(N^3)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxi=INT_MIN;
        int n = nums.size();

        for(int i=0;i<=n-1;i++)
        {
            for(int j=i;j<=n-1;j++)
            {
                int sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum += nums[k];
                    maxi = max(maxi,sum);
                }
            }
        }

        return maxi;
        
    }
};



// better
// tc - O(N^2)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxi=INT_MIN;
        int n = nums.size();

        for(int i=0;i<=n-1;i++)
        {
            int sum=0;
            for(int j=i;j<=n-1;j++)
            {
                sum += nums[j];
                maxi = max(maxi,sum);
            }
        }

        return maxi;
        
    }
};



//optimal - using kadane's algo
//tc - O(N)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxi=INT_MIN;
        int sum = 0;
        int n = nums.size();

        for(int i=0;i<=n-1;i++)
        {
            sum += nums[i];
            maxi = max(maxi,sum);
            if(sum < 0) sum=0;
        }

        return maxi;
        
    }
};