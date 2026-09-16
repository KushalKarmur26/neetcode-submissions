class Solution {

    vector<vector<int>> res;
    unordered_map<int,bool> available;
    vector<int> path;
    
    void helper(int total_size)
    {
        if(path.size()==total_size){
            res.push_back(path);
            return;
        }

        for(auto it:available)
        {
            if(it.second){
                path.push_back(it.first);
                available[it.first] = false;
                helper(total_size);

                path.pop_back();
                available[it.first] = true;
            }
        }

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        for(int i:nums) available[i] = true;

        helper(nums.size());

        return res;
        
    }
};
