class Solution {
public:
    
    vector<int> twoSum(vector<int>& numbers, int target) {

        int size = numbers.size();
        int front = 0;
        int rear = size-1;

        int currentsum = numbers[front] + numbers[rear];

        while(currentsum!=target)
        {
            if(currentsum>target) rear--;

            else front++;

            currentsum = numbers[front] + numbers[rear];
        }

        return {front+1,rear+1};
        
    }
};
