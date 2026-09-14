class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int size = s.size();

        unordered_map<char,bool> mp;

        int index = 0;
        queue<char> window;

        int maxlength=0;

        while(index<size)
        {
            
            if(mp.find(s[index]) == mp.end() || mp[s[index]]==false) //processed character is not present in the window;
            {
                window.push(s[index]);
                mp[s[index]] = true;
                index++;
            }

            else //pop until repeated letter
            {
                if(window.size()>maxlength) maxlength = window.size();
                
                while(window.front()!=s[index])
                {
                    mp[window.front()] = false;
                    window.pop();
                }
                mp[window.front()] = false;
                window.pop(); 
            }
        }

        if(window.size()>maxlength) maxlength = window.size();

        return maxlength;

        
    }
};
