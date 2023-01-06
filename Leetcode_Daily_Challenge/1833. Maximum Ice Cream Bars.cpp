//brute force approach
//tc - nlogn
//sc - logn for sorting

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int count=0;

        sort(costs.begin(),costs.end());

        for(int i=0;i<costs.size();i++)
        {
            if(costs[i] <= coins)
            {
                coins -= costs[i];
                count++;
            }

        }

        return count;
        
    }
};





//optimised
//tc n+m
//sc m

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int count=0;

        int m = *max_element(costs.begin(),costs.end());

        vector<int> freq(m+1,0);

        for(auto x : costs)
        {
            freq[x]++;
        }

        int ans = 0;

        for(int i=0;i<=m;i++)
        {
            if(freq[i]==0) continue;

            if(i>coins) break;

            else{
                int usedcoins = min(freq[i],coins/i);
                coins -= i*usedcoins;
                ans += usedcoins;
            }
        }

        return ans;
        
    }
};
