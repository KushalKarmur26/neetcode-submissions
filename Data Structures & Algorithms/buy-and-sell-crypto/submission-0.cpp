class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int size = prices.size();
        
        int front = 0;
        int rear = 0;

        int minele = prices[0];

        int maxprofit = 0;

        while(rear<size)
        {
            
            if(prices[rear]<minele)
            {
                minele = prices[rear];
                front = rear;
                rear++;
                continue;
            }

            int currentprofit = prices[rear] - prices[front];
            if(currentprofit>maxprofit) maxprofit = currentprofit;

            rear++;

        }

        return maxprofit;
        
    }
};
