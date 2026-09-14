class Solution {
public:

    int time(vector<int> &piles, int k)
    {
        int res = 0;

        for(int i:piles)
        {
            int temp = i/k;
            if(i%k!=0) temp++;

            res += temp;
        }

        return res;

    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int max = 0;

        for(int i:piles) if(i>max) max = i;

        int low = 1;
        int high = max;

        int ans;

        while(low<=high)
        {
            long mid = low + (high-low)/2;

            if(time(piles,mid)<=h)
            {
                ans = mid;
                high = mid - 1;
                continue;
            }

            low = mid + 1;
            continue;
        }
        

        return ans;
    }
};