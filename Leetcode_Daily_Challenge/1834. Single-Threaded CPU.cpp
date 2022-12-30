//tc - O(nlogn)
//sc - O(n)  

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        for(int i=0;i<tasks.size();i++)
        {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(),tasks.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;

        vector<int> ans;

        long long currtime = 0;
        int i=0;


        while(i<tasks.size() || !q.empty())
        {

            if(q.empty())
            {
                currtime = max(currtime,(long long)tasks[i][0]);
            }

            while(i<tasks.size() && tasks[i][0]<=currtime)
            {
                q.emplace(tasks[i][1],tasks[i][2]);
                i++;
            }

            auto[processingtime,index] = q.top(); 
            q.pop();

            currtime += processingtime;
            ans.push_back(index);

        }

        return ans;
        
    }
};

