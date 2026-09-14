class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,vector<int>,greater<int>> heap;

        for(int i : nums)
        {
            if(heap.size()<k) heap.push(i);

            else if(heap.top() < i)
            {
                heap.pop();
                heap.push(i);
            }
        }

        return heap.top();
        
    }
};
