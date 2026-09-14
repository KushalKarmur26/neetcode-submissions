class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int size = nums.size();

        unordered_map <int,bool> mp;

        for(int i:nums) mp[i] = true;

        int max = 0;

        for(auto &it:mp)
        {
            if(it.second)
            {
                mp[it.first] = false;
                int current = 1;

                int target = it.first - 1;
                while(mp.find(target)!=mp.end() && mp[target])
                {
                    current++;
                    mp[target] = false;
                    target--;
                }

                target = it.first + 1;

                while(mp.find(target)!=mp.end() && mp[target])
                {
                    current++;
                    mp[target] = false;
                    target++;
                }

                if(current>max) max = current;

            }
        }

        return max;
        
    }
};
