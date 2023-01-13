class Solution {
public:

    int ans=0;

    int dfs(vector<vector<int>>& adj,int src,int parent,string& s)
    {
        int longest = 0;
        int second_longest = 0;
        for(int& child : adj[src])
        {
            if(child==parent) continue;

            int child_longest_length = dfs(adj,child,src,s);

            if(s[child] == s[src]) continue;

            if(child_longest_length > longest)
            {
                second_longest = longest;
                longest = child_longest_length;
            }
            else if(child_longest_length > second_longest){
                second_longest = child_longest_length;
            }

        }

        int a = max(longest,second_longest) + 1;

        int b = 1;

        int c = longest + second_longest + 1;

        ans = max({ans,a,b,c});

        return max(a,b);

    }


    int longestPath(vector<int>& parent, string s) {

        int n = parent.size();

        vector<vector<int>> adj(n);


        for(int i=1;i<n;i++)
        {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        dfs(adj,0,-1,s);

        return ans;
        
    }
};