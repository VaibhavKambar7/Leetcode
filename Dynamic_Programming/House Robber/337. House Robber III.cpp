class Solution {
public:

    vector<int> f(TreeNode* root)
    {
        if(root == NULL)
        return vector<int> (2,0);

        vector<int> left = f(root->left);
        vector<int> right = f(root->right);

        vector<int> res(2,0);

        res[0] = root->val + left[1] + right[1];
        res[1] = max(left[0],left[1]) + max(right[0],right[1]); 

        return res;
    }


    int rob(TreeNode* root) {

        vector<int> res = f(root);
    
        return max(res[0],res[1]) ;
        
    }
};