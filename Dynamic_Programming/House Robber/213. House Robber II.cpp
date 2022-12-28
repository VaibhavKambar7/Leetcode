//space optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }


    int robber(vector<int>& nums, int begin, int end) {
        int prev = 0, prev2 = 0;
        for (int i = begin; i <= end; i++) {
            int curr = max(prev2 + nums[i], prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
