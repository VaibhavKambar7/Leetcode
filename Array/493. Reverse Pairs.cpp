//brute force approach
//tc = O(n^2)
//sc = O(1)

class Solution {
public:
    int reversePairs(vector<int>& nums) {

        int n = nums.size();
        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i] > 2 * nums[j]) count++;
            }
        }

        return count;
        
    }
};



//optimised
//tc = O(nlogn) + O(n) + O(n) -> mergesort + merge + count
//sc = O(n) ->a[]


class Solution {
private:
    int count;
    void merge(vector<int>& nums, int start, int mid, int end) {
        int l = start, r = mid + 1;
        while (l <= mid && r <= end){
            if ((long) nums[l] > (long) 2 * nums[r]){
                count += (mid - l + 1);
                r++;
            }else {
                l++;
            }
        }
        int a[end - start + 1], t = 0;
        l = start, r = mid + 1;
        while (l <= mid and r <= end) {
            if (l <= mid and nums[l] < nums[r]) {
                a[t++] = nums[l++];
            } else {
                a[t++] = nums[r++];
            }
        }
        while (l <= mid) {
            a[t++] = nums[l++];
        }
        while (r <= end) {
            a[t++] = nums[r++];
        }
        for (int i = 0; i < end - start + 1; i++) {
            nums[start + i] = a[i];
        }
        return;
    }
    void mergeSort(vector<int>& nums, int start, int end){
        if(start == end) return;
        int mid = (start + end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1,end);
        merge(nums, start, mid, end);
        return;
    }
public:
    int reversePairs(vector<int>& nums) {
        if (!nums.size()) return 0;
        count = 0;
        mergeSort(nums, 0, nums.size()-1);
        return count;
    }
};
