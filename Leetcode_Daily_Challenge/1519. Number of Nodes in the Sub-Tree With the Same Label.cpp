class Solution {
public:
   vector<vector<int>>adjlist;
   vector<int>ans;

    vector<int>  dfs(string &labels,int currentNode,int parent){

        vector<int>count(26,0);

        for(auto x:adjlist[currentNode]){
            if(x != parent){

                auto temp = dfs(labels,x,currentNode);
                for(int i=0;i<26;i++){
                    count[i]+=temp[i]; 
                }
            }
         }

        int ch = labels[currentNode]-'a'; 
        count[ch]++;

        ans[currentNode] = count[ch];

        return count;

    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adjlist.resize(n);
        ans.resize(n,1);
        
        for(auto x:edges){
            adjlist[x[0]].push_back(x[1]);
            adjlist[x[1]].push_back(x[0]);
        }
        
        dfs(labels,0,-1);

        return ans;
    }
};