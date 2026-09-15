class Solution {

    int pathsum = 0;
    vector<vector<int>> res;
    vector<int> path;

    void helper(int index,int target, vector<int> nums)
    {
        for(int i=index;i<nums.size();i++)
        {
            if(pathsum + nums[i] < target)
            {
                path.push_back(nums[i]);
                pathsum += nums[i];

                helper(i, target, nums);

                path.pop_back();
                pathsum -= nums[i];
            }

            if(pathsum + nums[i]==target)
            {
                path.push_back(nums[i]);
                res.push_back(path);

                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        helper(0, target, nums);

        return res;
        
    }
};
