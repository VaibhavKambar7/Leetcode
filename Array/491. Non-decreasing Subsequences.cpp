//bactracking

class Solution {
public:
    void func(int idx,vector<int>&nums,vector<int>&a,set<vector<int>>&ans){
        int n=nums.size();
        if(idx>=n){
            if(a.size()>=2){
                ans.insert(a);
            }
            return ;
        }
        if(a.empty()||nums[idx]>=a.back()){
            a.push_back(nums[idx]);
            func(idx+1,nums,a,ans);
            a.pop_back();
        }
        func(idx+1,nums,a,ans); 
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        set<vector<int>>ans;
        func(0,nums,temp,ans);
        return vector(ans.begin(),ans.end());
        
    }
};


//dfs

class Solution {
public:
    void dfs(vector<int>&nums, int idx, int prev, vector<int>& subseq, vector<vector<int>>& res){
        if(subseq.size()>=2){
            res.push_back(subseq);

            if( idx==nums.size())
                return;
        }

        unordered_set<int> us;

        for(int i=idx; i<nums.size(); i++){

            if( prev<= nums[i] and us.find(nums[i]) == us.end()){
                subseq.push_back(nums[i]);
                us.insert(nums[i]);
                dfs(nums, i+1, nums[i], subseq, res);
                subseq.pop_back();
            }

        }
    }    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subseq;

        dfs(nums, 0, -101, subseq, res);
        return res;
    }
};