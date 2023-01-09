class Solution {
public:
    
    void Traverse(TreeNode* root,vector<int>& a)
    {
        if(root==NULL)
        {
            return ;
        }

        Traverse(root->left,a);
        Traverse(root->right,a);
        a.push_back(root->val);
    }
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> vt;
        Traverse(root,vt);
            return vt;
            
    }
};