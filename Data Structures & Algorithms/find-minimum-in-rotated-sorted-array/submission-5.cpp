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

        int low = 0;
        int high = size-1;

        int min;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(mid!=0 && nums[mid]<nums[mid-1]) return nums[mid];

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
