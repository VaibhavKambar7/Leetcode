class Solution {
public:

    int kadane(vector<int>& nums)
    {
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

    int maxSubarraySumCircular(vector<int>& nums) {

        int maxsubarr = kadane(nums);

        int countpositive = 0;

        int totalsumnegative = 0;

        for(int i=0;i<nums.size();i++)
        {
            nums[i] = -1 * nums[i];
            if(nums[i] > 0) countpositive++;
            totalsumnegative += nums[i]; 
        }

        if(countpositive == nums.size()) return maxsubarr;

        int maxpartedsubarr = kadane(nums);

        int maxpartedsubarrans = -1 * (totalsumnegative - maxpartedsubarr);

        return max(maxsubarr,maxpartedsubarrans);
        
    }
};