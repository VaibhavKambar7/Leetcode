class Solution {

    private:
    void dfs(vector<vector<int>>& ans, const vector<vector<bool>>& vis,
             int i, int j, int oc, int c){
        
        if(i<0 || j<0 || i>=ans.size() || j>= ans[0].size() || vis[i][j]==1 ||
          ans[i][j]==c || ans[i][j]!=oc)
            return;
        
        ans[i][j] = c;
        
        dfs(ans, vis, i+1, j, oc, c);
        dfs(ans, vis, i-1, j, oc, c);
        dfs(ans, vis, i, j+1, oc, c);
        dfs(ans, vis, i, j-1, oc, c);
        
    }
    
    
    public:
    vector<vector<int>> floodFill(vector<vector<int>>& ans, int sr, int sc, int c) {

        if(ans[sr][sc]==c)
            return ans;
        int oc = ans[sr][sc];
        vector<vector<bool>> vis(ans.size(), vector<bool>(ans[0].size(), 0));
        dfs(ans, vis, sr, sc, oc, c);
        return ans;
        
        
    }
};