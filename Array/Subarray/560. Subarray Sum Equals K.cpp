class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        if(n==0) return 0;

        unordered_map<int,int> map;

        int count=0;
        int curr_sum = 0;
        int i=0;

        while(i<n)
        {
            curr_sum += nums[i];

            if(curr_sum == k) count++;

            if(map.find(curr_sum-k) != map.end())
            {
                count += map[curr_sum-k];

            }
                map[curr_sum]++;
                i++;

        }

        return count;

    }
};