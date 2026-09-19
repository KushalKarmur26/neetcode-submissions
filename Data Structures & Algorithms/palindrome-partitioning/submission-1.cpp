class Solution {

    bool ispalindrome(int low,int high, string &s)
    {
        while(low<=high)
        {
            if(s[low]!=s[high]) return false;
            low++;
            high--;
        }

        return true;
    }

    void dfs(vector<int> &bars,string &s,vector<vector<string>> &res)
    {
        int last_bar = bars[bars.size()-1];
        
        if(last_bar!=-1 && last_bar==s.size()-2) return;

        for(int i=last_bar+1;i<=s.size()-2;i++)
        {
            bars.push_back(i); //insert new bar
            
            //checking palindrome property of all substrings
            bool push = true;
            bool lastdefect = false;

            for(int j=1;j<bars.size();j++)
            {
                
                
                push = ispalindrome(bars[j-1]+1,bars[j],s);
                if(!push) break;

                if(j==bars.size()-1)
                {
                    push = ispalindrome(bars[j]+1,s.size()-1,s);
                    if(!push) 
                        lastdefect = true;
                }

            }

            if(push)
            {
                vector<string> temp;
                for(int j=0;j<bars.size();j++)
                {
                    if(j!=bars.size()-1) temp.push_back( s.substr(bars[j]+1, bars[j+1]-bars[j]) );

                    //last bar
                    else temp.push_back( s.substr(bars[j]+1, s.size()-bars[j]) );
                }

                res.push_back(temp);

            }


            if(push || lastdefect)
                dfs(bars,s,res);

            bars.pop_back();
        }
    }


public:
    vector<vector<string>> partition(string s) {

            vector<vector<string>> res;
            vector<int> bars;

            if(ispalindrome(0,s.size()-1,s))
            {
                vector<string> temp;
                temp.push_back(s);
                res.push_back(temp);
            }

            if(s.size()==1) return res;
            
            bars.push_back(-1);
            dfs(bars,s,res);

            return res;
        
    }
};
