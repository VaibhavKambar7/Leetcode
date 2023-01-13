class Solution {
public:

    int f(TreeNode* root,int& maxi)
    {
        if(root==NULL) return 0;

        int left = max(0,f(root->left,maxi));
        int right = max(0,f(root->right,maxi));

        maxi = max(maxi,root->val+left+right);

        return root->val + max(left,right);

    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;
        f(root,maxi);
        return maxi;

    }
};