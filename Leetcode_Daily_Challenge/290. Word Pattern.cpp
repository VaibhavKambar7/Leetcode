class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char,string> mp;
        unordered_map<string,bool> visited;

        vector<string> wordlist;

        stringstream st(s);

        string word ;
        int count = 0;

        while(st >> word)
        {
            count++;
            wordlist.push_back(word);
        }

        if(pattern.size() != count)
        {
            return false;
        }
        else{
            for(int i=0;i<pattern.size();i++)
            {
                char c = pattern[i];

                if(mp[c]=="" && visited[wordlist[i]]==true) return false;

                else if(mp[c]==""){
                    mp[c] = wordlist[i];
                    visited[wordlist[i]] = true;
                }

                else{
                    if(mp[c] != wordlist[i]) return false;
                }

            }
        }
        return true;
        
    }
};