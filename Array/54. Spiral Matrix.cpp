class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {

        int dir = 0;
        int T=0,B=A.size()-1,R=A[0].size()-1,L=0;
        vector<int> ans;

        while(T<=B && L<=R)
        {
            if(dir==0)
            {
                for(int j=L;j<=R;j++)
                {
                    ans.push_back(A[T][j]);
                }
                T++;
            }
            else if(dir==1)
            {
                for(int i=T;i<=B;i++)
                {
                    ans.push_back(A[i][R]);
                }
                R--;
            }
            else if(dir==2)
            {
                for(int j=R;j>=L;j--)
                {
                    ans.push_back(A[B][j]);
                }
                B--;
            }
            else if(dir==3)
            {
                for(int i=B;i>=T;i--)
                {
                    ans.push_back(A[i][L]);
                }
                L++;
            }

            dir = (dir+1)%4;
        }

        return ans;

    }
};