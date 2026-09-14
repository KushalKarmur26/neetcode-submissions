class Solution {

private:

    bool inposn(int current,int curr_index)
    {
        return (current==curr_index+1);
    }

public:
    int findDuplicate(vector<int>& nums) {

        int index = 0;
        int size = nums.size();

        while(index<size)
        {
            
            int current = nums[index];

            while(!inposn(current,index))
            {
                if(current==nums[current-1]) return current;

                swap(nums[index],nums[current-1]);
                current = nums[index];
            }

            index++;

        }
        
    }
};
