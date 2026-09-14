class Solution {

    queue<vector<int>> myqueue;
    queue<int> lastindex;


public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int size = nums.size();

        myqueue.push({});
        lastindex.push(-1);

        vector<vector<int>> res;
        res.push_back({});

        while(!myqueue.empty())
        {
            //vector<int> current = myqueue.front();
            int marker = lastindex.front();

            for(int i=marker+1;i<size;i++)
            {
                vector<int> newset = myqueue.front();
                newset.push_back(nums[i]);

                myqueue.push(newset);
                res.push_back(newset);
                lastindex.push(i);

            }

            myqueue.pop();
            lastindex.pop();

        }

        return res;
        
    }
};
