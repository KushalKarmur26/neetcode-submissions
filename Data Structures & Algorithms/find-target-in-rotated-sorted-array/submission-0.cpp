class Solution {
public:
    int search(vector<int>& nums, int target) {

        int size = nums.size();

        int low = 0;
        int high = size-1;

        int minindex;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid]<=nums[size-1])
            {
                minindex = mid;
                high = mid - 1;
            }

            else low = mid + 1;
        }

        if(target<=nums[size-1])
        {
            low = minindex;
            high = size-1;
        }

        else
        {
            low = 0;
            high = minindex - 1;
        }

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid]==target) return mid;
            if(target<nums[mid]) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
        
    }
};
