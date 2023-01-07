class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        queue<pair<TreeNode*,pair<int,int>>> todo;
        map<int,map<int,multiset<int>>> nodes;

        todo.push({root,{0,0}});

        while(!todo.empty())
        {
            auto t = todo.front();
            todo.pop();
            TreeNode* node = t.first;
            int x=t.second.first,y=t.second.second;

            nodes[x][y].insert(node->val);

            if(node->left)
            {
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right)
            {
                todo.push({node->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans;

         for(auto p : nodes)
        {
            vector<int> cal;
            for(auto q : p.second)
            {
                cal.insert(cal.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(cal);
        }

        return ans;
        
    }
};