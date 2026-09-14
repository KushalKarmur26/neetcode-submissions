class Solution {
public:

    int mysearch(vector<int> &nums, int low, int high, int target)
    {
        int mid = low + (high-low)/2;

        if(nums[mid]==target) return mid;

        if(low>=high) return -1;

        if(target<nums[mid]) return mysearch(nums,low,mid-1,target);

        return mysearch(nums,mid+1,high,target);
    }

    int search(vector<int>& nums, int target) {

        int size = nums.size();
        return mysearch(nums,0,size-1,target);
        
    }
};
