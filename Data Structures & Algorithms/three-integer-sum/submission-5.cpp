class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>> res;


        for(int mp=0;mp<nums.size();mp++)
        {
            if(nums[mp]>0) break;
            if(mp>=1 && nums[mp]==nums[mp-1]) continue;

            int target = -nums[mp];
            int low = mp+1;
            int high = nums.size()-1;

            while(low<high)
            {
                if( (low>mp+1 && high<nums.size()-1) && (nums[low-1]==nums[low] &&            nums[high]==nums[high+1]) )
                {
                    low++;
                    high--;
                    continue;
                }

                if(nums[low]+nums[high] > target)
                {
                    high--;
                    continue;
                }

                if(nums[low]+nums[high] < target)
                {
                    low++;
                    continue;
                }

                if(nums[low]+nums[high]==target)
                {
                    res.push_back( {nums[mp],nums[low],nums[high]} );
                    low++;
                    high--;
                    continue;
                }


            }
        }

        return res;
        
    }
};
