class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int n = points.size();

        int ans=1;

        for(int i=0;i<=n-2;i++)
        {
            unordered_map<double,int> map;
            for(int j=i+1;j<=n-1;j++)
            {
                if(points[i][0]==points[j][0]) map[100000001]++;
                else{

                    double slope = (double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                    
                    map[slope]++;
                }

            }
                int temp=0;

                for(auto x:map)
                {
                    temp=max(temp,x.second);
                }

                ans = max(ans,temp+1);
        }
        
        return ans;
    
    }
};