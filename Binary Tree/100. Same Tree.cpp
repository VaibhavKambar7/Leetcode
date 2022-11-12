


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        

        
        if(p==NULL || q==NULL)
        {
            return ;
        }
        
        if(p->val!=q->val)
        {
            return false;
        }
        
        isSameTree(p->left,q->left);
        isSameTree(p->right,q->right);

        
    }
};