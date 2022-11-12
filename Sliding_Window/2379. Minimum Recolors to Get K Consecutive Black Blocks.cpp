class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int front=0,back=0,count=0,ans=INT_MAX;

        while(front < blocks.size())
        {
            if(blocks[front]=='W') count++;
            if(front - back + 1 ==k)
            {
                ans = min(ans,count);
                if(blocks[back] == 'W') count--;
                back++;
            }
            front++;
        }

        return ans;


        
    }
};