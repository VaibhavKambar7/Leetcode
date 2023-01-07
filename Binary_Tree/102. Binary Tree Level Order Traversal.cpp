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
            vector<int> result;
            
            for(int i=0;i<size;i++)
            {
                TreeNode* nodes = q.front();
                q.pop();
                if(i==size-1)
                {
                    result.push_back(nodes->val);
                }
                level.push_back(nodes->val);
                if(nodes->left !=NULL) q.push(nodes->left);
                if (nodes->right !=NULL) q.push(nodes->right);
            }
            ans.push_back(result);
        }
        return ans;
    }
};