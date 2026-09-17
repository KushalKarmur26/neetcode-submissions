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
                int sum = nums[low]+nums[high];

                if(sum > target) high--;

                else if(sum < target) low++;

                else
                {
                    res.push_back( {nums[mp],nums[low],nums[high]} );
                    low++;
                    high--;

                    while( (low<high) && (nums[low]==nums[low-1] && nums[high]==nums[high+1]) )
                    {
                        low++;
                        high--;
                    }
                }


            }
        }

        return res;
        
    }
};
