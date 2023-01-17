class Solution {
public:

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
        
            curr[target]=(notTaken + taken);
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


 int findTargetSumWays(vector<int>& nums, int target) {

    int n = nums.size();


    return countPartitions(n,target,nums);
    
    }
};