class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        
        int size = nums.size();
        vector<int> res;
        vector<vector<int>> mybucket(size);

        unordered_map<int,int> mp;

        for(int i:nums) mp[i]++;

        for(auto &it : mp)
        {
            mybucket[it.second-1].push_back(it.first);
        }

        int count = 0;

        for(int i=size-1;i>=0;i--)
        {
            if(mybucket[i].empty()) continue;

            for(int ans : mybucket[i])
            {
                if(count==k) break;
                res.push_back(ans);
                count++;
            }

            if(count==k) break;
        }

        return res;
        
    }
};
