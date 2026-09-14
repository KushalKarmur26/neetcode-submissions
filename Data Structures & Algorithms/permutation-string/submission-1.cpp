class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int size1 = s1.size();
        int size2 = s2.size();
        
        if(size1>size2) return false;

        unordered_map<char,int> mp;

        for(char c:s1) mp[c]++;

        int low = 0;
        int high = 0;

        int matched = 0;

        while(high<size2)
        {
            if(mp.find(s2[high]) == mp.end())
            {
                while(low!=high)
                {
                    mp[s2[low]] ++;
                    low++;
                }
                low++;
                high++;
                matched = 0;
            }

            else if(mp[s2[high]]==0)
            {
                while(s2[low]!=s2[high])
                {
                    mp[s2[low]] ++;
                    low++;
                }
                low++;
                high++;
                matched = high-low;
            }

            else
            {
                mp[s2[high]]--;
                high++;
                matched++;

                if(matched==size1) return true;
            }
        }

        return false;
        
    }
};
