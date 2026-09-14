class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;
        int size = nums.size();

        for(int i:nums) mp[i]++;

        int index1 = 0;
        int index2 = 0;
        int find = 0;

        for(int i=0;i<size;i++)
        {
            int second = target - nums[i];
            if(second == nums[i])
            {
                if(mp[second] > 1)
                {
                    index1 = i;
                    find = second;
                    break;
                }
            }

            else if(mp[second]>0)
            {
                index1 = i;
                find = second;
                break;
            }

        }

        for(int i=0;i<size;i++)
        {
            if(nums[i]==find && i!=index1)
            {
                index2 = i;
                break;
            }

        }

        return {index1,index2};
        
    }
};
