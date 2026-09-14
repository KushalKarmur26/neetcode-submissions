class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int size = nums.size();
        int withoutzero = 1;
        int zerocount = 0;
        vector<int> res;

        for(int i : nums)
        {
            //withzero *= i;

            if(i==0)
            {
                zerocount++;
                if(zerocount>1)
                {
                    for(int i=0;i<size;i++) res.push_back(0);
                    return res;
                }
                continue;
            }

            
            withoutzero *= i;
        }

        if(zerocount)
        {
            for(int i=0;i<size;i++)
            {
                if(nums[i]==0) res.push_back(withoutzero);
                else res.push_back(0);
            }
        }

        else for(int i=0;i<size;i++) res.push_back(withoutzero/nums[i]);

        return res;

    }
};
