//  https://leetcode.com/problems/binary-tree-inorder-traversal/


class Solution {
public:
    
    void Traverse(TreeNode* root,vector<int>& a)
    {
        if(root==NULL)
        {
            return ;
        }
        
        
        Traverse(root->left,a);
        a.push_back(root->val);
        Traverse(root->right,a);
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
  
        
        vector<int> vt;
        Traverse(root,vt);
            return vt;
        
    }
};