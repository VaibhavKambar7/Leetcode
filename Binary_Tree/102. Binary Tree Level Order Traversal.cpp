class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            
            for(int i=0;i<size;i++)

            {
                TreeNode* nodes = q.front();
                q.pop();

                if(nodes->left !=NULL) q.push(nodes->left);
                if (nodes->right !=NULL) q.push(nodes->right);
                
                level.push_back(nodes->val);
            }
            
            ans.push_back(level);
            
        }
        
        return ans;
        
    }
};