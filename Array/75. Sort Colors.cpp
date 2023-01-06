class Solution {
public:
    void sortColors(vector<int>& nums) {

        // sort(nums.begin(),nums.end()); tc O(nlogn)

        //tc O(n)
        int low,mid,high;
        low=0;
        mid=0;
        high=nums.size()-1;

        while(mid<=high){

            if(nums[mid] == 1)
            {
                mid++;
                continue;
            }

            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
                continue;
            }
            if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
                continue;
            }
        }
    }
};