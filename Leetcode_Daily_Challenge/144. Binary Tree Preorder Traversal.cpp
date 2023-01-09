class Solution {
public:
    
    void Traverse(TreeNode* root,vector<int>& a)
    {
        if(root==NULL)
        {
            return ;
        }
        
        a.push_back(root->val);
        Traverse(root->left,a);
        Traverse(root->right,a);
    }
    
    
    vector<int> preorderTraversal(TreeNode* root) {
  
        
        vector<int> vt;
        Traverse(root,vt);
            
        return vt;
        
    }
};