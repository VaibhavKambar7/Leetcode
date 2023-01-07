class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currgas = 0;
        int totalgas = 0;
        int start = 0;

        for(int i=0;i<gas.size();i++)
        {
            currgas += gas[i] - cost[i];

            totalgas += gas[i] - cost[i];

            if(currgas < 0 )
            {
                currgas = 0;
                start = i+1;
            }
        }

        return totalgas>=0?start:-1;

    }
};