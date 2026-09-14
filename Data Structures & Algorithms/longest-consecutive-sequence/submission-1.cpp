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
                it.second = false;
                int current = 1;

                int target = it.first - 1;
                auto it2 = mp.find(target);

                while(it2 != mp.end() && it2->second)
                {
                    current++;
                    it2->second = false;
                    target--;

                    it2 = mp.find(target);
                }

                target = it.first + 1;
                it2 = mp.find(target);

                while(it2 != mp.end() && it2->second)
                {
                    current++;
                    it2->second = false;
                    target++;

                    it2 = mp.find(target);
                }

                if(current>max) max = current;

            }
        }

        return max;
        
    }
};
