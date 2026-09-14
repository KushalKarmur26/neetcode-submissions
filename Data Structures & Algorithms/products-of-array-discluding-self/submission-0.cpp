class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int size = nums.size();
        int withzero = 1;
        int withoutzero = 1;
        int zerocount = 0;
        vector<int> res;

        for(int i : nums)
        {
            withzero *= i;

            if(i==0)
            {
                zerocount++;
                continue;
            }
            withoutzero *= i;
        }

        if(zerocount>1)
        {
            for(int i=0;i<size;i++) res.push_back(0);
            return res;
        }

        for(int i=0;i<size;i++)
        {
            if(nums[i]!=0) res.push_back(withzero/nums[i]);

            else res.push_back(withoutzero);
        }

        return res;

    }
};
