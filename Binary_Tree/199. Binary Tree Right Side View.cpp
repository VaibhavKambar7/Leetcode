class Solution {
public:

    void right(TreeNode* root,int level,vector<int>& v)
    {
        if(!root) return;

        if(level == v.size())
        {
            v.push_back(root->val);
        }

        right(root->right,level + 1,v);
        right(root->left,level + 1,v);

    }


    vector<int> rightSideView(TreeNode* root) {

        vector<int> v;
        int level=0;
        
        right(root,level,v);

        return v;
    }
};