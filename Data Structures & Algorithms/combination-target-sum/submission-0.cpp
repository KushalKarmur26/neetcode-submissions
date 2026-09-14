class Solution {

    int currentsum = 0;
    vector<vector<int>> res;

    void helper(int index,int target,vector<int> &path,vector<int> &nums)
    {

        if(index>=nums.size()) return;

        if(currentsum + nums[index] < target)
        {
            path.push_back(nums[index]);
            currentsum += nums[index];

            helper(index,target,path,nums);

            currentsum -= path[path.size()-1];
            path.pop_back();

            helper(index+1,target,path,nums);
        }

        else if(currentsum + nums[index] == target)
        {
            path.push_back(nums[index]);
            
            res.push_back(path);
            
            path.pop_back();

            helper(index+1,target,path,nums);

        }

        else
        {
            helper(index+1,target,path,nums);
        }

    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<int> path;
        
        helper(0,target,path,nums);

        return res;
        
    }
};
