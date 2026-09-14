class Solution {
public:

    bool onright(int index, vector<int> &nums)
    {
        int size = nums.size();

        if(nums[index]<=nums[size-1]) return true;

        return false;
    }

    int findMin(vector<int> &nums) {

        int size = nums.size();

        /*if(size==1) return nums[0];

        if(nums[0]<nums[size-1]) return nums[0]; //check for unrotated array*/

        int low = 0;
        int high = size-1;

        int min;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(onright(mid,nums))
            {
                min = nums[mid]; 
                high = mid-1;
            }

            else low = mid+1;
            
        }

        return min;
        
    }
};
