class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int,int>> mystack;
        int size = temperatures.size();

        vector<int> res(size);

        for(int index=0;index<size;index++)
        {
            int buffer = temperatures[index];
            
            if(mystack.empty()) mystack.push({buffer, index});

            else
            {
                while(!mystack.empty())
                {
                    pair<int,int> top = mystack.top();

                    if(top.first>=buffer) break;

                    res[top.second] = index - top.second;
                    mystack.pop();
                }

                mystack.push({buffer, index});

            }
            
        }

        return res;
    }
};
