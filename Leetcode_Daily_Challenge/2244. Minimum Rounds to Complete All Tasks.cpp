class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        unordered_map<int,int> map;

        for(int i=0;i<tasks.size();i++)
        {
            map[tasks[i]]++;
        }

        int ans=0;

        for(auto x : map)
        {
            int freq = x.second;

            if(freq == 1) return -1;

            else if(freq % 3 == 0) ans = ans + freq / 3;

            else if(freq % 3 == 2) ans = ans + (freq / 3) + 1;

            else if(freq % 3 == 1) ans = ans + (freq / 3) + 1;

        }

        return ans;
        
    }
};

