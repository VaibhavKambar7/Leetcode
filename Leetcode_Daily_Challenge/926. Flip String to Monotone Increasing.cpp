class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int countone=0;
        int countflip=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '1') countone++;

            else
            {
                countflip++;
                countflip = min(countflip,countone);
            }
        }
        return countflip;
    }
};