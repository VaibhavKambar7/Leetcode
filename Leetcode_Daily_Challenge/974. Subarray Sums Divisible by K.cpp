class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        if(n==0) return 0;
        int count = 0;
        int curr_sum=0;
        // int ans;
        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i=0;i<n;i++)
        {
            curr_sum += nums[i];
            int rem = curr_sum % k;
            if(rem<0) rem+=k;

            if(mp.find(rem)!=mp.end())
                count+=mp[rem];

            mp[rem]++;
        }

        return count;
        
    }
};